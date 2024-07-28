#include "events.h"
#include <stdio.h>

void onTestEvent(Event *event) {
  if (event->type == Test) {
    printf("Person, name: %s, age: %u\n", event->data.test.name, event->data.test.age);
  }
}

int main(void) {
  events_setup();
  events_register_event_subscriber(onTestEvent);
  printf("Hello, World, %zu\n", sizeof(FnEventCallback));
  Event event = {.type = Test, .data = {.test = {.name = "Jeff", .age = 20}}};
  events_post_event(&event);
}
