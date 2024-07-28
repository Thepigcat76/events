#include "events.h"
#include "surtils/src/collections/vec.h"
#include <stdio.h>

vec_t *event_subscribers;

void events_setup() { event_subscribers = vec_new(); }

void events_register_event_subscriber(FnEventCallback callback) {
  vec_push_back(event_subscribers, (void *)callback);
}

void events_post_event(Event *event) {
    printf("len: %zu\n", event_subscribers->length);
    for (size_t i = 0; i < event_subscribers->length; i++) {
        FnEventCallback callback = (FnEventCallback) vec_get(event_subscribers, i);
        callback(event);
    }
}