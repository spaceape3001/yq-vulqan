////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AScale1.hpp>
#include <ya/commands/scale/AddScale1.hpp>
#include <ya/commands/scale/AddScaleX.hpp>
#include <ya/commands/scale/MultiplyScale.hpp>
#include <ya/commands/scale/MultiplyScale1.hpp>
#include <ya/commands/scale/MultiplyScaleX.hpp>
#include <ya/commands/scale/SetScale1.hpp>
#include <ya/commands/scale/SetScaleX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale¹::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IScale¹>();
        w.property(UNSAFE, "scale", &AScale¹::m_scale).tag(kTag_Save);

        w.slot(UNSAFE, &AScale¹::on_set_scale1);
        w.slot(UNSAFE, &AScale¹::on_set_scaleX);

        w.slot(UNSAFE, &AScale¹::on_add_scale1);
        w.slot(UNSAFE, &AScale¹::on_add_scaleX);
        
        w.slot(UNSAFE, &AScale¹::on_multiply_scale);
        w.slot(UNSAFE, &AScale¹::on_multiply_scale1);
        w.slot(UNSAFE, &AScale¹::on_multiply_scaleX);
    }
}
