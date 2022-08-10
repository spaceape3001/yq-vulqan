////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    namespace engine {
        class Event {
        public:
            virtual ~Event();
        };
        
        class Command : public Event {
        public:
            virtual ~Command();
        };
        
        class Input : public Event {
        public:
            virtual ~Input();
        };
    }
}
