////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/APosition2.hpp>
#include <yq/tachyon/command/position/AddPosition2Command.hpp>
#include <yq/tachyon/command/position/AddPositionXCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2Command.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <yq/tachyon/command/position/SetPosition2Command.hpp>
#include <yq/tachyon/command/position/SetPositionXCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition²::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition²>();
        w.property(UNSAFE, "position", &APosition²::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition²::on_set_position2);
        w.slot(UNSAFE, &APosition²::on_set_positionX);
        w.slot(UNSAFE, &APosition²::on_set_positionY);

        w.slot(UNSAFE, &APosition²::on_add_position2);
        w.slot(UNSAFE, &APosition²::on_add_positionX);
        w.slot(UNSAFE, &APosition²::on_add_positionY);
        
        w.slot(UNSAFE, &APosition²::on_multiply_position);
        w.slot(UNSAFE, &APosition²::on_multiply_position2);
        w.slot(UNSAFE, &APosition²::on_multiply_positionX);
        w.slot(UNSAFE, &APosition²::on_multiply_positionY);
    }
}
