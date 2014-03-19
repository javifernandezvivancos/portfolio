/** GENERIC FUNCTIONS **/

var ajax_request = function(data, callback, fail)
{
	console.log("Sending Request:");
	console.log(data);
	var request = $.ajax({
		url:'./php/api.php',
		async:data.async == undefined? undefined : data.async,
		type:data.type == undefined? 'get' : data.type,
		data:data,
		success:callback,
		error:fail,
	});
}

var get_cache = function(str){
	return $.parseJSON($.cookie(str));
}

var cache = function(str, obj){
	$.cookie(str, JSON.stringify(obj));
}

var gmap_link = function(user){
	var place = user.city+', '+user.state;
	return '<a target="blank" href="http://maps.google.com/maps?q='+escape(place)+'">'+place+'</a>';
}

/** USER FUNCTIONS **/
var add_user = function(e)
{
	e.preventDefault();
	ajax_request({
		script:'users',
		action:'add_user',
		first:$('#first').val(),
		last:$('#last').val(),
		email:$('#email').val(),
		pass:$('#pass').val(),
	}, function(response){
		user_obj = $.parseJSON(response);
		$.cookie('user', response);
		router.navigate("user/"+user_obj.id, true);
	}, function(response){
		console.log('ERROR!');
		console.log(response);
	});
}

var login_user = function(e)
{
	e.preventDefault();
	ajax_request({
		async:false,
		script:'users',
		action:'get_user',
		email:$('#login-email').val(),
		pass:$('#login-password').val(),
	}, function(response, success, jqXHR){
		user_obj = $.parseJSON(response);
		$.cookie('user', response);
		router.navigate('profile', true);
	}, function(response){
		$('#password').val('');
	});
}

var get_user = function(id)
{
	var ajax;
	ajax_request({
		async:false,
		script:'users',
		action:'user_by_id',
		id:id,
	}, function(response, success, jqXHR){
		ajax = $.parseJSON(response);
	}, function(response){
		$('#password').val('');
	});
	return ajax;
}

var update_user = function(e){
	e.preventDefault();
	// ajax_request({
	// 	script:'users',
	// 	action:'update_user',
	// }, function(response, success, jqXHR){
	// 	console.log('update_user');
	// 	user_obj = $.parseJSON(response);
	// 	$.cookie('user', response);
	// 	router.navigate('user/'+user_obj.id, true);
	// }, function(response){
	// 	$('#password').val('');
	// });	
	router.navigate('user/'+user_obj.id, true);
}

var user_link = function(user)
{
	return '<a href="#user/'+user.id+'">'+user.firstname+' '+user.lastname+'</a>';
}

var search_users = function(e)
{
	console.log('clicked');
	ajax_request({
		script:'users',
		action:'get_user',
		email:'bluehugh2@gmail.com',
		pass:'boylan55'
	}, function(response){
		console.log(response);
	}, function(error){
		console.log('error');
	});
}

/** EVENT FUNCTIONS **/
var create_event = function(e)
{
	e.preventDefault();
	ajax_request({
		script:'events',
		action:'add_event',
		uid:user_obj.id,
		name:$('#eventname').val(),
	}, function(response, success, jqXHR){
		response = $.parseJSON(response);
		console.log(response);
		if(response.success)
		{
			$('#events-form-modal').modal('hide');
			var e = response.event;
			router.navigate('events/'+escape(e.title), {trigger:true});
		}
	});
}


/** TEAM FUNCTIONS **/

var create_team = function(e){
	e.preventDefault();
	ajax_request({
		script:'teams',
		action:'add_team',
		owner:user_obj.id,
		name:$('#teamname').val(),
	}, function(response, success, jqXHR){
		var ajax = $.parseJSON(response);
		$('#teams-form-modal').modal('hide');
		router.navigate('teams/'+ajax.team.id, {trigger:true});
	}, function(response){
		console.log("ERROR");
		console.log(response);
	});
}

var get_team = function(id)
{
	var ajax;
	ajax_request({
		async:false,
		script:'teams',
		action:'get_team',
		teamid:id,
	}, function(response, success, jqXHR){
		ajax = $.parseJSON(response);
		console.log(ajax);
	}, function(response){
		console.log("ERROR");
		console.log(response);
	});
	return ajax;
}

var team_link = function(team)
{
	return '<a href="#teams/'+team.id+'">'+team.teamname+'</a>';
}

var user_teams_table = function(user)
{
	var teams;
	ajax_request({
		async:false,
		script:'users',
		action:'user_teams',
		id:user.id,
	}, function(response, success, jqXHR){
		teams = $.parseJSON(response);
		console.log(teams);
	}, function(response){
		console.log("ERROR");
		console.log(response);
	});
	var rows = [];
	for(team in teams){
		var t = teams[team];
		rows.push({cls:'success', data:[team_link(t), t.sports]});
	}
	return {headers:['Name', 'Sports'], rows:rows};
}

var team_table = function(players)
{
	var rows = [];
	for(player in players){
		var p = players[player];
		rows.push({cls:'success', data:[user_link(p), gmap_link(p), p.sports]});
	}
	return {headers:['Player', 'Location', 'Sports'], rows:rows};
}


