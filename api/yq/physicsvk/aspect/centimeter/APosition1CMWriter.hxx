////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physicsvk/aspect/centimeter/APosition1CM.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPosition1CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPosition1CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition¹CM::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition¹CM>();
        w.property(UNSAFE, "position", &APosition¹CM::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition¹CM::on_set_position1);
        w.slot(UNSAFE, &APosition¹CM::on_set_positionX);

        w.slot(UNSAFE, &APosition¹CM::on_add_position1);
        w.slot(UNSAFE, &APosition¹CM::on_add_positionX);
        
        w.slot(UNSAFE, &APosition¹CM::on_multiply_position);
        w.slot(UNSAFE, &APosition¹CM::on_multiply_position1);
        w.slot(UNSAFE, &APosition¹CM::on_multiply_positionX);
    }
}
