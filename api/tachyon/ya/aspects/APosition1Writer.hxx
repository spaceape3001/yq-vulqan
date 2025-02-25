////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/APosition1.hpp>
#include <ya/commands/position/AddPosition1.hpp>
#include <ya/commands/position/AddPositionX.hpp>
#include <ya/commands/position/MultiplyPosition.hpp>
#include <ya/commands/position/MultiplyPosition1.hpp>
#include <ya/commands/position/MultiplyPositionX.hpp>
#include <ya/commands/position/SetPosition1.hpp>
#include <ya/commands/position/SetPositionX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition¹::init_info(TachyonInfo::Writer<C>& w)
    {
        w.template interface<IPosition¹>();
        w.property(UNSAFE, "position", &APosition¹::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition¹::on_set_position1);
        w.slot(UNSAFE, &APosition¹::on_set_positionX);

        w.slot(UNSAFE, &APosition¹::on_add_position1);
        w.slot(UNSAFE, &APosition¹::on_add_positionX);
        
        w.slot(UNSAFE, &APosition¹::on_multiply_position);
        w.slot(UNSAFE, &APosition¹::on_multiply_position1);
        w.slot(UNSAFE, &APosition¹::on_multiply_positionX);
    }
}
