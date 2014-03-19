var searchKey = '', user_obj = get_cache('user');

var r = Backbone.Router.extend({
	routes: {
		"": "",
		"search":"search",
		"sign_up":"sign_up",
		"user/:uid":"user",
		"teams/:teamname":"team",
		"events/:eventname":"event",
		"logout":"logout",
		"profile":"profile",
		"profile/:settings":"profile",
	},
	"logout":function(settings){
		$.cookie('user', '');
		router.navigate('', {trigger:true});
		window.location.reload();
	},
});
var router = new r();

//This is the Backbone controller that manages the content of the app
var App = Backbone.View.extend({
	el:$('.content-container'),
	initialize:function(options){
		Backbone.history.on('route',function(source, path, extension){
			$('.dropdown.open .dropdown-toggle').dropdown('toggle');
			if(path in this.content) this.render(path, extension);
		}, this);
	},
	render:function(route, ext){
		//Simply sets the content as appropriate
		$('body').css('background-image','');
		this.$el.html(new this.content[route]().render(ext));
	},
	events:{
		'click #friend-user-btn':function(e){
			e.preventDefault();
			alert('friend user');
		},
		'click #invite-user-btn':function(e){
			e.preventDefault();
			alert('invite user to event');
		},
	},
	//This object defines the content for each of the routes in the application
	content:{
		"":Backbone.View.extend({
			template:$('#home-template').html(),
			render:function(){
				return _.template(this.template, {});
			},
		}),
		
		"search":Backbone.View.extend({
			el:$('.content-container'),
			template:$('#search-template').html(),
			render:function(){
				return _.template(this.template, {search:searchKey});
			},
			events:{
				'click .search-submit':search_users,
			}
		}),
		
		"sign_up":Backbone.View.extend({
			el:$('.content-container'),
			template:$('#user-signup-template').html(),
			render:function(){
				$('.preview').css('background-image','./img/ultimate-frisbee.jpg');
				return _.template(this.template, {});
			},
			events:{
				'submit #signup-form':add_user,
			},
		}),
		
		"profile":Backbone.View.extend({
			el:$('.content-container'),
			template:$('#user-profile-template').html(),
			render:function(settings){
				// var user = user_obj == undefined;
				// if(user && settings)
				// 	router.navigate
				// else if(user) //Value user logged in
				// 	router.navigate('/', true);
				console.log(user_obj);
				user_obj.location = gmap_link(user_obj);
				
				var teamForm = {id:'teams-form', header:'Create A New Team!'},
				// eventForm = {id:'events-form', header:'Create A New Event!'},
				sections = [
					{id:'teams', 	title:'Teams', 	viewData:user_teams_table(user_obj), 	action:'Create Team', 	modal:teamForm},
					// {id:'events', 	title:'Events',	viewData:{},	action:'Create Event',	modal:eventForm},
				];
				return _.template(this.template, {user:user_obj, sections:[]})
			},
			events:{
				'submit .teams-form':create_team,
				'click .teams-form-btn':create_team,
				'submit .events-form':create_event,
				'click .events-form-btn':create_event,
				'click #settings-user-btn':function(e){
					e.preventDefault();
					router.navigate('user/settings', true);
				},
			},
		}),
		
		"team":Backbone.View.extend({
			el:$('.content-container'),
			template:$('#team-profile-template').html(),
			render:function(teamid){
				var ajax = get_team(teamid[0]);
				return _.template(this.template, {team:ajax.team, players:team_table(ajax.players)});
			},
		}),
		
		"event":Backbone.View.extend({
			el:$('.content-container'),
			template:$('#event-profile-template').html(),
			render:function(eventname){
				return _.template(this.template, {title:eventname});
			},
		}),
		
		"user-settings":Backbone.View.extend({
			el:$('.content-container'),
			template:$('#user-settings-template').html(),
			render:function(){
				return _.template(this.template, {user:user_obj});
			},
			events:{
				'click #save-user-btn':update_user,
			}
		}),
	},
});

//This is the Backbone controller that manages the Nav Bar
var NavBar = Backbone.View.extend({
	id:'#dynamic-navbar',
	el:$('.content-navbar'),
	initialize:function(options){
		Backbone.history.on('route',function(source, path){ this.render(path); }, this);
	},
	//This is a collection of possible routes and their accompanying
	//user-friendly titles
	titles: {
		"":"Home",
		"search":"Search",
	},
	events:{
		'click a':function(source) {
			var hrefRslt = source.target.getAttribute('href');
			router.navigate(hrefRslt, true);
			//Cancel the regular event handling so that we won't actual change URLs
			//We are letting Backbone handle routing
			return false;
		},
		'keypress .search-query':function(e){
			setTimeout(function(){
				searchKey = e.target.value;
				router.navigate("#home", {trigger:true});
				router.navigate("#search", {trigger:true});
				if(e.keyCode == 13)	e.preventDefault();
			}, 1);
		},
		'click .dropdown-toggle.sign-in':function(e){
			console.log('happened');
			$('#email').focus();
		},
		'submit #login-form':login_user,
	},
	//Each time the routes change, we refresh the navigation
	//items.
	render:function(route){
		// $(this.id).empty();
		// var template = _.template("<li class='<%=active%>'><a href='<%=url%>'><%=visible%></a></li>");
		// for (var key in this.titles)	$(this.id).append(template({url:key,visible:this.titles[key],active:route === key ? 'active' : ''}));
		if(route != "sign_up")
		{
			var signup_tmpl = '<li><a href="#sign_up" id="signup">Sign Up</a></li><li class="divider-vertical"></li>',
				login_tmpl = '<li class="dropdown">'+$('#user-dropdown-template').html()+'</li>',
			tmpl = user_obj == undefined? signup_tmpl + login_tmpl : login_tmpl;
			$('#user-dropdown').html(_.template(tmpl, {user:user_obj}));

			$('.dropdown-toggle').dropdown();
			$('.dropdown input, .dropdown label, .dropdown#user-dropdown').click(function(e) {
				e.stopPropagation();
			});
		}
	},
});

//Attach Backbone Views to existing HTML elements
new NavBar();
new App();

//Start the app by setting kicking off the history behaviour.
//We will get a routing event with the initial URL fragment
Backbone.history.start();