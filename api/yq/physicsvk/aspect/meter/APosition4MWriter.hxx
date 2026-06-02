////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physicsvk/aspect/meter/APosition4M.hpp>
#include <yq/physicsvk/command/position/meter/AddPosition4MCommand.hpp>
#include <yq/physicsvk/command/position/meter/AddPositionWMCommand.hpp>
#include <yq/physicsvk/command/position/meter/AddPositionXMCommand.hpp>
#include <yq/physicsvk/command/position/meter/AddPositionYMCommand.hpp>
#include <yq/physicsvk/command/position/meter/AddPositionZMCommand.hpp>
#include <yq/physicsvk/command/position/meter/SetPosition4MCommand.hpp>
#include <yq/physicsvk/command/position/meter/SetPositionWMCommand.hpp>
#include <yq/physicsvk/command/position/meter/SetPositionXMCommand.hpp>
#include <yq/physicsvk/command/position/meter/SetPositionYMCommand.hpp>
#include <yq/physicsvk/command/position/meter/SetPositionZMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition⁴M::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition⁴M>();
        w.property(UNSAFE, "position", &APosition⁴M::m_position).tag(kTag_Save);
        
        w.slot(UNSAFE, &APosition⁴M::on_set_position4);
        w.slot(UNSAFE, &APosition⁴M::on_set_positionW);
        w.slot(UNSAFE, &APosition⁴M::on_set_positionX);
        w.slot(UNSAFE, &APosition⁴M::on_set_positionY);
        w.slot(UNSAFE, &APosition⁴M::on_set_positionZ);

        w.slot(UNSAFE, &APosition⁴M::on_add_position4);
        w.slot(UNSAFE, &APosition⁴M::on_add_positionW);
        w.slot(UNSAFE, &APosition⁴M::on_add_positionX);
        w.slot(UNSAFE, &APosition⁴M::on_add_positionY);
        w.slot(UNSAFE, &APosition⁴M::on_add_positionZ);
        
        w.slot(UNSAFE, &APosition⁴M::on_multiply_position);
        w.slot(UNSAFE, &APosition⁴M::on_multiply_position4);
        w.slot(UNSAFE, &APosition⁴M::on_multiply_positionW);
        w.slot(UNSAFE, &APosition⁴M::on_multiply_positionX);
        w.slot(UNSAFE, &APosition⁴M::on_multiply_positionY);
        w.slot(UNSAFE, &APosition⁴M::on_multiply_positionZ);
    }
}
