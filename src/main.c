#include "events.h"
#include <stdio.h>
#include <unistd.h>

void onTestEvent(Event *event) {
  TestEvent test_event = event->data.test;
  printf("Person, name: %s, age: %u\n", test_event.name, event->data.test.age);
}

void onDeezEvent(Event *event) {
  printf("Deez nuts, count: %d!\n", event->data.deez.count);
}

int main(void) {
  // Initial setup
  events_setup();

  // Setup event subscribers
  EventType test_type = Test;
  events_register_event_subscriber(onTestEvent, &test_type);
  EventType deez_type = Deez;
  events_register_event_subscriber(onDeezEvent, &deez_type);

  // Post the event
  Event event = {.type = Test, .data = {.test = {.name = "Jeff", .age = 20}}};
  Event test_evt =
      events_new_event(Test, (EventData){.test = {.name = "Jeff", .age = 20}});
  events_post_event(&event);

  sleep(1);

  Event deez_evt = {.type = Deez, .data = {.deez = {.count = 100}}};
  events_post_event(&deez_evt);
}
