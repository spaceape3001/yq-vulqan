////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/APosition3.hpp>
#include <ya/commands/spatial/AddPosition3.hpp>
#include <ya/commands/spatial/AddPositionX.hpp>
#include <ya/commands/spatial/AddPositionY.hpp>
#include <ya/commands/spatial/AddPositionZ.hpp>
#include <ya/commands/spatial/MultiplyPosition.hpp>
#include <ya/commands/spatial/MultiplyPosition3.hpp>
#include <ya/commands/spatial/MultiplyPositionX.hpp>
#include <ya/commands/spatial/MultiplyPositionY.hpp>
#include <ya/commands/spatial/MultiplyPositionZ.hpp>
#include <ya/commands/spatial/SetPosition3.hpp>
#include <ya/commands/spatial/SetPositionX.hpp>
#include <ya/commands/spatial/SetPositionY.hpp>
#include <ya/commands/spatial/SetPositionZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition³::init_info(TachyonInfo::Writer<C>& w)
    {
        w.template interface<IPosition³>();
        
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
