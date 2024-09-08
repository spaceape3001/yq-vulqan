////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/Manipulator.hpp>

namespace yq {
    namespace asset {
        class SpaceManipulator : public engine::Manipulator {
            YQ_OBJECT_DECLARE(SpaceManipulator, engine::Manipulator)
        public:
        
            SpaceManipulator();
            ~SpaceManipulator();
        };
    }
}
