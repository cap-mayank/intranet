(function($){
$(document).ready(function() {
			$('.anniversaryAjaxHandler').css("visibility", "hidden");
			$('.birthDayAjaxHandler').css("visibility", "hidden");
			var holidayEvents = Drupal.settings.holiday_node.holidays_json;			
			var EventsJsons = Drupal.settings.holiday_node.event_json;
			var defaultDate = holidayEvents[0]['field_publishing_date'].split('-')[0]+'-01-01';
			var i=0,annPresent=0,birthPresent=0;
			for (variable in holidayEvents) {
				var event ={
					"title" : holidayEvents[i]['field_holiday_name'],
					"start" : holidayEvents[i]['field_publishing_date'],
				}
				holidayYear = 
				EventsJsons.push(event);
				i++;
			}	
			$('#calendar').fullCalendar({
			header: {
				left: 'prev,next today',
				center: 'title',
				right: 'month,basicWeek,basicDay'
			},
			defaultDate: defaultDate,
			editable: false,
			eventLimit: true, // allow "more" link when too many events
			events: EventsJsons,
			eventColor: '#378006',
			eventRender: function(event, element) {
				/*if(event.start.getMonth() !== view.start.getMonth()) { 
					return false; 
				}*/
				if(event.className == 'calendarAnniversary'){
					element.append('<div class="hCalAnniversary"></div>');
				}
				else if(event.className == 'calendarBirthday'){
					element.append('<div class="hCalBirthday"></div>');
				}
			},
			eventClick: function(calEvent, jsEvent, view) {
				
			},
			dayClick: function(date, jsEvent, view) {	
				var dayEvents = 	$('#calendar').fullCalendar('clientEvents', function(event) {
					if(moment(event.start).isSame(date,'day')){
						if(event.className == 'calendarAnniversary'){
							annPresent = 1;
							return event;
						}
						else if(event.className == 'calendarBirthday'){
							birthPresent = 1;
							return event;
						}
					}
				}); 
				i=0;
				if(dayEvents === undefined || dayEvents.length == 0){
					$('.anniversaryAjaxHandler').css("visibility", "hidden");
					$('.birthDayAjaxHandler').css("visibility", "hidden");
					$('.clickedDate').css("visibility", "hidden");
				}
				else{
					if(annPresent == 1){
						$('.anniversaryAjaxHandler').css("visibility", "visible").children('div.annUser').remove();
						annPresent = 0;
					}
					else{
						$('.anniversaryAjaxHandler').css("visibility", "hidden").children('div.annUser').remove();
					}
					if(birthPresent == 1){
						
						$('.birthDayAjaxHandler').css("visibility", "visible").children('div.holUser').remove();
						birthPresent = 0;
					}
					else{
						console.log('Here');
						$('.birthDayAjaxHandler').css("visibility", "hidden").children('div.holUser').remove().remove();
					}
					$('.clickedDate').css("visibility", "visible");
					$('.clickedDate').html(dayEvents[0].start['_i']);
					for(dayEvent in dayEvents){
							if(dayEvents[i].className == 'calendarAnniversary'){
								$('.anniversaryAjaxHandler').append('<div class="annUser"><div class="holPic"><img src="'+dayEvents[i].userpicture+'"/></div><div class="holName">'+dayEvents[i].username+'</div></div>');
							}
							else{
								$('.birthDayAjaxHandler').append('<div class="holUser"><div class="holPic"><img src="'+dayEvents[i].userpicture+'"/></div><div class="holName">'+dayEvents[i].username+'</div>');
							}
							i++;
					}
					$('html, body').animate({
						scrollTop: $(".newScroll").offset().top
					}, 1000);
				}
			}
		});
});

})(jQuery);