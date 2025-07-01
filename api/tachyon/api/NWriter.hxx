////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

/*
    Due to the irregular inheritance patterns, we need the base classes to 
    register handlers, however, it'd be burdensome to make the users do all 
    the heavy lifting.  Therefore, the base classes within the tachyon library
    can call these... outside users won't need to as the regular inheritance
    mechanisms will work.
*/

#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/api/N.hpp>
#include <tachyon/event/SpatialEvent.hpp>
#include <tachyon/command/SpatialCommand.hpp>
#include <tachyon/command/generic/SetSpatialCommand.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void     И::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.slot(UNSAFE, &И::on_spatial_command);
        w.slot(UNSAFE, &И::on_spatial_event);
        w.slot(UNSAFE, &И::on_set_spatial_command);
        w.property(UNSAFE, "spatial", &И::m_spatial).tag({kTag_Save, kTag_TachyonID});
    }
}

