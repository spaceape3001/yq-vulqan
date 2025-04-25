////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AScale2.hpp>
#include <tachyon/command/scale/AddScale2.hpp>
#include <tachyon/command/scale/AddScaleX.hpp>
#include <tachyon/command/scale/AddScaleY.hpp>
#include <tachyon/command/scale/MultiplyScale.hpp>
#include <tachyon/command/scale/MultiplyScale2.hpp>
#include <tachyon/command/scale/MultiplyScaleX.hpp>
#include <tachyon/command/scale/MultiplyScaleY.hpp>
#include <tachyon/command/scale/SetScale2.hpp>
#include <tachyon/command/scale/SetScaleX.hpp>
#include <tachyon/command/scale/SetScaleY.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale²::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IScale²>();
        w.property(UNSAFE, "scale", &AScale²::m_scale).tag(kTag_Save);

        w.slot(UNSAFE, &AScale²::on_set_scale2);
        w.slot(UNSAFE, &AScale²::on_set_scaleX);
        w.slot(UNSAFE, &AScale²::on_set_scaleY);

        w.slot(UNSAFE, &AScale²::on_add_scale2);
        w.slot(UNSAFE, &AScale²::on_add_scaleX);
        w.slot(UNSAFE, &AScale²::on_add_scaleY);
        
        w.slot(UNSAFE, &AScale²::on_multiply_scale);
        w.slot(UNSAFE, &AScale²::on_multiply_scale2);
        w.slot(UNSAFE, &AScale²::on_multiply_scaleX);
        w.slot(UNSAFE, &AScale²::on_multiply_scaleY);
    }
}
