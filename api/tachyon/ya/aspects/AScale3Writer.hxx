////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AScale3.hpp>
#include <tachyon/command/scale/AddScale3.hpp>
#include <tachyon/command/scale/AddScaleX.hpp>
#include <tachyon/command/scale/AddScaleY.hpp>
#include <tachyon/command/scale/AddScaleZ.hpp>
#include <tachyon/command/scale/MultiplyScale.hpp>
#include <tachyon/command/scale/MultiplyScale3.hpp>
#include <tachyon/command/scale/MultiplyScaleX.hpp>
#include <tachyon/command/scale/MultiplyScaleY.hpp>
#include <tachyon/command/scale/MultiplyScaleZ.hpp>
#include <tachyon/command/scale/SetScale3.hpp>
#include <tachyon/command/scale/SetScaleX.hpp>
#include <tachyon/command/scale/SetScaleY.hpp>
#include <tachyon/command/scale/SetScaleZ.hpp>
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
