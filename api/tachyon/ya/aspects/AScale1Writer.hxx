////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AScale1.hpp>
#include <ya/commands/spatial/AddScale1.hpp>
#include <ya/commands/spatial/AddScaleX.hpp>
#include <ya/commands/spatial/MultiplyScale.hpp>
#include <ya/commands/spatial/MultiplyScale1.hpp>
#include <ya/commands/spatial/MultiplyScaleX.hpp>
#include <ya/commands/spatial/SetScale1.hpp>
#include <ya/commands/spatial/SetScaleX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale¹::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IScale¹>();
        w.property(UNSAFE, "scale", &AScale¹::m_scale);

        w.slot(UNSAFE, &AScale¹::on_set_scale1);
        w.slot(UNSAFE, &AScale¹::on_set_scaleX);

        w.slot(UNSAFE, &AScale¹::on_add_scale1);
        w.slot(UNSAFE, &AScale¹::on_add_scaleX);
        
        w.slot(UNSAFE, &AScale¹::on_multiply_scale);
        w.slot(UNSAFE, &AScale¹::on_multiply_scale1);
        w.slot(UNSAFE, &AScale¹::on_multiply_scaleX);
    }
}
