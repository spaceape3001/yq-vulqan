////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/meter/APosition1M.hpp>
#include <yq/tachyon/command/position/meter/AddPosition1MCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPosition1MCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionXMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition¹M::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition¹M>();
        w.property(UNSAFE, "position", &APosition¹M::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition¹M::on_set_position1);
        w.slot(UNSAFE, &APosition¹M::on_set_positionX);

        w.slot(UNSAFE, &APosition¹M::on_add_position1);
        w.slot(UNSAFE, &APosition¹M::on_add_positionX);
        
        w.slot(UNSAFE, &APosition¹M::on_multiply_position);
        w.slot(UNSAFE, &APosition¹M::on_multiply_position1);
        w.slot(UNSAFE, &APosition¹M::on_multiply_positionX);
    }
}
