////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/APosition3.hpp>
#include <ya/commands/position/AddPosition3.hpp>
#include <ya/commands/position/AddPositionX.hpp>
#include <ya/commands/position/AddPositionY.hpp>
#include <ya/commands/position/AddPositionZ.hpp>
#include <ya/commands/position/MultiplyPosition.hpp>
#include <ya/commands/position/MultiplyPosition3.hpp>
#include <ya/commands/position/MultiplyPositionX.hpp>
#include <ya/commands/position/MultiplyPositionY.hpp>
#include <ya/commands/position/MultiplyPositionZ.hpp>
#include <ya/commands/position/SetPosition3.hpp>
#include <ya/commands/position/SetPositionX.hpp>
#include <ya/commands/position/SetPositionY.hpp>
#include <ya/commands/position/SetPositionZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition³::init_info(TachyonInfo::Writer<C>& w)
    {
        w.template interface<IPosition³>();
        w.property(UNSAFE, "position", &APosition³::m_position).tag(kTag_Save);
        
        w.slot(UNSAFE, &APosition³::on_set_position3);
        w.slot(UNSAFE, &APosition³::on_set_positionX);
        w.slot(UNSAFE, &APosition³::on_set_positionY);
        w.slot(UNSAFE, &APosition³::on_set_positionZ);

        w.slot(UNSAFE, &APosition³::on_add_position3);
        w.slot(UNSAFE, &APosition³::on_add_positionX);
        w.slot(UNSAFE, &APosition³::on_add_positionY);
        w.slot(UNSAFE, &APosition³::on_add_positionZ);
        
        w.slot(UNSAFE, &APosition³::on_multiply_position);
        w.slot(UNSAFE, &APosition³::on_multiply_position3);
        w.slot(UNSAFE, &APosition³::on_multiply_positionX);
        w.slot(UNSAFE, &APosition³::on_multiply_positionY);
        w.slot(UNSAFE, &APosition³::on_multiply_positionZ);
    }
}
