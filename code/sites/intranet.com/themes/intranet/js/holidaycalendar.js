(function ($) {
    $(document).ready(function () {
        $('.anniversaryAjaxHandler').css("visibility", "hidden");
        $('.birthDayAjaxHandler').css("visibility", "hidden");
        var holidayEvents = Drupal.settings.holiday_node.holidays_json;
        var anniversaryDateArray = [];
        var birthdayDateArray = [];
        $.getJSON("/sites/intranet.com/files/event_birth_anniversary.json", function (data) {
            var EventsJsons = data;
            var i = 0, annPresent = 0, birthPresent = 0;
            for (variable in holidayEvents) {
                var event = {
                    "title": holidayEvents[i]['field_holiday_name'],
                    "start": holidayEvents[i]['field_publishing_date'],
                }
                EventsJsons.push(event);
                i++;
            }
            $('#calendar').fullCalendar({
                header: {
                    left: 'prev,next today',
                    center: 'title',
                    right: 'month,basicWeek,basicDay'
                },
                editable: false,
                eventLimit: true, // allow "more" link when too many events
                events: EventsJsons,
                eventColor: '#378006',
                displayEventTime: false,
                eventRender: function (event, element) {
                    if (event.className == 'calendarAnniversary') {  
                       //checking if another anniversary is present on the same day.
                       if (jQuery.inArray(event.start['_i'], anniversaryDateArray) == -1){
                          anniversaryDateArray.push(event.start['_i']); 
                          element.append('<div class="hCalAnniversary"></div>'); 
                       }  
                    } else if (event.className == 'calendarBirthday') {
                        //checking if another birthday is present on the same day.
                      if (jQuery.inArray(event.start['_i'], birthdayDateArray) == -1){
                          birthdayDateArray.push(event.start['_i']); 
                          element.append('<div class="hCalBirthday"></div>'); 
                       } 
                    }
                },
                eventClick: function (calEvent, jsEvent, view) {

                },
                dayClick: function (date, jsEvent, view) {
                    var dayEvents = $('#calendar').fullCalendar('clientEvents', function (event) {
                        if (moment(event.start).isSame(date, 'day')) {
                            if (event.className == 'calendarAnniversary') {
                                annPresent = 1;
                                return event;
                            } else if (event.className == 'calendarBirthday') {
                                birthPresent = 1;
                                return event;
                            }
                        }
                    });
                    i = 0;
                    if (dayEvents === undefined || dayEvents.length == 0) {
                        $('.anniversaryAjaxHandler').css("visibility", "hidden");
                        $('.birthDayAjaxHandler').css("visibility", "hidden");
                        $('.clickedDate').css("visibility", "hidden");
                    } else {
                        if (annPresent == 1) {
                            $('.anniversaryAjaxHandler').css("visibility", "visible").children('div.annUser').remove();
                            annPresent = 0;
                        } else {
                            $('.anniversaryAjaxHandler').css("visibility", "hidden").children('div.annUser').remove();
                        }
                        if (birthPresent == 1) {

                            $('.birthDayAjaxHandler').css("visibility", "visible").children('div.holUser').remove();
                            birthPresent = 0;
                        } else {
                            $('.birthDayAjaxHandler').css("visibility", "hidden").children('div.holUser').remove().remove();
                        }
                        $('.clickedDate').css("visibility", "visible");
                        $('.clickedDate').html(moment(dayEvents[0].start['_i']).format('DD-MMM-YY '));
                        for (dayEvent in dayEvents) {
                            if (dayEvents[i].className == 'calendarAnniversary') {
                                $('.anniversaryAjaxHandler').append('<div class="annUser"><div class="holPic"><img src="' + dayEvents[i].userpicture + '"/></div><div class="holName">' + dayEvents[i].username + '</div></div>');
                            } else {
                                $('.birthDayAjaxHandler').append('<div class="holUser"><div class="holPic"><img src="' + dayEvents[i].userpicture + '"/></div><div class="holName">' + dayEvents[i].username + '</div>');
                            }
                            i++;
                        }
                        $('html, body').animate({
                            scrollTop: $(".newScroll").offset().top
                        }, 1000);
                    }
                },
                eventAfterAllRender: function(){
                  anniversaryDateArray = [];
                  birthdayDateArray = [];
                }
            });
        });
    });

})(jQuery);