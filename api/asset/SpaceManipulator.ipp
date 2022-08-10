////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SpaceManipulator.hpp"
#include <basic/DelayInit.hpp>

namespace yq {
    namespace asset {
        SpaceManipulator::SpaceManipulator()
        {
        }
        
        SpaceManipulator::~SpaceManipulator()
        {
        }
        
        YQ_INVOKE(
            [[maybe_unused]] auto smanip = writer<SpaceManipulator>();
        )
    }
}

YQ_OBJECT_IMPLEMENT(yq::asset::SpaceManipulator)

