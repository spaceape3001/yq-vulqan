////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physicsvk/aspect/meter/APosition2M.hpp>
#include <yq/tachyon/command/position/meter/AddPosition2MCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionYMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPosition2MCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionYMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition²M::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition²M>();
        w.property(UNSAFE, "position", &APosition²M::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition²M::on_set_position2);
        w.slot(UNSAFE, &APosition²M::on_set_positionX);
        w.slot(UNSAFE, &APosition²M::on_set_positionY);

        w.slot(UNSAFE, &APosition²M::on_add_position2);
        w.slot(UNSAFE, &APosition²M::on_add_positionX);
        w.slot(UNSAFE, &APosition²M::on_add_positionY);
        
        w.slot(UNSAFE, &APosition²M::on_multiply_position);
        w.slot(UNSAFE, &APosition²M::on_multiply_position2);
        w.slot(UNSAFE, &APosition²M::on_multiply_positionX);
        w.slot(UNSAFE, &APosition²M::on_multiply_positionY);
    }
}
