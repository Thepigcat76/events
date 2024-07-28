#pragma once

#include "eventsdef.h"

typedef union {
  TestEvent test;
} EventData;

typedef enum {
  Test,
} EventType;

typedef struct {
  EventType type;
  EventData data;
} Event;

typedef void (*FnEventCallback)(Event *event);

void events_setup();

void events_register_event_subscriber(FnEventCallback callback);

void events_post_event(Event *event);
