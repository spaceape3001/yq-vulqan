////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AScale1.hpp>
#include <tachyon/command/scale/AddScale1.hpp>
#include <tachyon/command/scale/AddScaleX.hpp>
#include <tachyon/command/scale/MultiplyScale.hpp>
#include <tachyon/command/scale/MultiplyScale1.hpp>
#include <tachyon/command/scale/MultiplyScaleX.hpp>
#include <tachyon/command/scale/SetScale1.hpp>
#include <tachyon/command/scale/SetScaleX.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

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
