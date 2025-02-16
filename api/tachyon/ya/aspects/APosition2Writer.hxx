////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/APosition2.hpp>
#include <ya/commands/spatial/AddPosition2.hpp>
#include <ya/commands/spatial/AddPositionX.hpp>
#include <ya/commands/spatial/AddPositionY.hpp>
#include <ya/commands/spatial/MultiplyPosition.hpp>
#include <ya/commands/spatial/MultiplyPosition2.hpp>
#include <ya/commands/spatial/MultiplyPositionX.hpp>
#include <ya/commands/spatial/MultiplyPositionY.hpp>
#include <ya/commands/spatial/SetPosition2.hpp>
#include <ya/commands/spatial/SetPositionX.hpp>
#include <ya/commands/spatial/SetPositionY.hpp>
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
