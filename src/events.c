#include "events.h"
#include "surtils/src/collections/vec.h"

vec_t *event_subscribers;
vec_t *event_types;

void events_setup() {
  event_subscribers = vec_new();
  event_types = vec_new();
}

Event events_new_event(EventType type, EventData data) {
  return (Event){.type = type, .data = data};
}

void events_register_event_subscriber(FnEventCallback callback,
                                      EventType *event_type) {
  vec_push_back(event_subscribers, (void *)callback);
  vec_push_back(event_types, event_type);
}

void events_post_event(Event *event) {
  for (size_t i = 0; i < event_subscribers->length; i++) {
    if (event->type == *(EventType *)vec_get(event_types, i)) {
      FnEventCallback callback = (FnEventCallback)vec_get(event_subscribers, i);
      callback(event);
    }
  }
}