////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/APosition2.hpp>
#include <ya/commands/position/AddPosition2.hpp>
#include <ya/commands/position/AddPositionX.hpp>
#include <ya/commands/position/AddPositionY.hpp>
#include <ya/commands/position/MultiplyPosition.hpp>
#include <ya/commands/position/MultiplyPosition2.hpp>
#include <ya/commands/position/MultiplyPositionX.hpp>
#include <ya/commands/position/MultiplyPositionY.hpp>
#include <ya/commands/position/SetPosition2.hpp>
#include <ya/commands/position/SetPositionX.hpp>
#include <ya/commands/position/SetPositionY.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition²::init_info(TachyonInfo::Writer<C>& w)
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
