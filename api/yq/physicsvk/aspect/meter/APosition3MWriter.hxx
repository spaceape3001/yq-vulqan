////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physicsvk/aspect/meter/APosition3M.hpp>
#include <yq/tachyon/command/position/meter/AddPosition3MCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionYMCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionZMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPosition3MCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionYMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionZMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition³M::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition³M>();
        w.property(UNSAFE, "position", &APosition³M::m_position).tag(kTag_Save);
        
        w.slot(UNSAFE, &APosition³M::on_set_position3);
        w.slot(UNSAFE, &APosition³M::on_set_positionX);
        w.slot(UNSAFE, &APosition³M::on_set_positionY);
        w.slot(UNSAFE, &APosition³M::on_set_positionZ);

        w.slot(UNSAFE, &APosition³M::on_add_position3);
        w.slot(UNSAFE, &APosition³M::on_add_positionX);
        w.slot(UNSAFE, &APosition³M::on_add_positionY);
        w.slot(UNSAFE, &APosition³M::on_add_positionZ);
        
        w.slot(UNSAFE, &APosition³M::on_multiply_position);
        w.slot(UNSAFE, &APosition³M::on_multiply_position3);
        w.slot(UNSAFE, &APosition³M::on_multiply_positionX);
        w.slot(UNSAFE, &APosition³M::on_multiply_positionY);
        w.slot(UNSAFE, &APosition³M::on_multiply_positionZ);
    }
}
