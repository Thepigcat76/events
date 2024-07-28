#pragma once

#include "eventsdef.h"

typedef union {
  TestEvent test;
  DeezEvent deez;
} EventData;

typedef enum {
  Test,
  Deez,
} EventType;

typedef struct {
  EventType type;
  EventData data;
} Event;

typedef void (*FnEventCallback)(Event *event);

void events_setup();

void events_register_event_subscriber(FnEventCallback callback, EventType *event_type);

void events_post_event(Event *event);

Event events_new_event(EventType type, EventData data);
