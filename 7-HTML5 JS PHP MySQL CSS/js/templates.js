var Section = Backbone.View.extend({
	template:$('#section-template').html(),
	initialize:function(id, title, content){
		this.options = {
			id:id,
			title:title,
			content:content,
		};
	},
	render:function(){
		return _.template(this.template, this.options);
	},
});