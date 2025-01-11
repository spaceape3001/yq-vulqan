////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/APosition1.hpp>
#include <ya/commands/spatial/AddPosition1.hpp>
#include <ya/commands/spatial/AddPositionX.hpp>
#include <ya/commands/spatial/MultiplyPosition.hpp>
#include <ya/commands/spatial/MultiplyPosition1.hpp>
#include <ya/commands/spatial/MultiplyPositionX.hpp>
#include <ya/commands/spatial/SetPosition1.hpp>
#include <ya/commands/spatial/SetPositionX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition¹::init_info(TachyonInfo::Writer<C>& w)
    {
        w.template interface<IPosition¹>();

        w.slot(UNSAFE, &APosition¹::on_set_position1);
        w.slot(UNSAFE, &APosition¹::on_set_positionX);

        w.slot(UNSAFE, &APosition¹::on_add_position1);
        w.slot(UNSAFE, &APosition¹::on_add_positionX);
        
        w.slot(UNSAFE, &APosition¹::on_multiply_position);
        w.slot(UNSAFE, &APosition¹::on_multiply_position1);
        w.slot(UNSAFE, &APosition¹::on_multiply_positionX);
    }
}
