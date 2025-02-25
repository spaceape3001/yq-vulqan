////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AScale3.hpp>
#include <ya/commands/scale/AddScale3.hpp>
#include <ya/commands/scale/AddScaleX.hpp>
#include <ya/commands/scale/AddScaleY.hpp>
#include <ya/commands/scale/AddScaleZ.hpp>
#include <ya/commands/scale/MultiplyScale.hpp>
#include <ya/commands/scale/MultiplyScale3.hpp>
#include <ya/commands/scale/MultiplyScaleX.hpp>
#include <ya/commands/scale/MultiplyScaleY.hpp>
#include <ya/commands/scale/MultiplyScaleZ.hpp>
#include <ya/commands/scale/SetScale3.hpp>
#include <ya/commands/scale/SetScaleX.hpp>
#include <ya/commands/scale/SetScaleY.hpp>
#include <ya/commands/scale/SetScaleZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale³::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IScale³>();
        w.property(UNSAFE, "scale", &AScale³::m_scale).tag(kTag_Save);
        
        w.slot(UNSAFE, &AScale³::on_set_scale3);
        w.slot(UNSAFE, &AScale³::on_set_scaleX);
        w.slot(UNSAFE, &AScale³::on_set_scaleY);
        w.slot(UNSAFE, &AScale³::on_set_scaleZ);

        w.slot(UNSAFE, &AScale³::on_add_scale3);
        w.slot(UNSAFE, &AScale³::on_add_scaleX);
        w.slot(UNSAFE, &AScale³::on_add_scaleY);
        w.slot(UNSAFE, &AScale³::on_add_scaleZ);
        
        w.slot(UNSAFE, &AScale³::on_multiply_scale);
        w.slot(UNSAFE, &AScale³::on_multiply_scale3);
        w.slot(UNSAFE, &AScale³::on_multiply_scaleX);
        w.slot(UNSAFE, &AScale³::on_multiply_scaleY);
        w.slot(UNSAFE, &AScale³::on_multiply_scaleZ);
    }
}
