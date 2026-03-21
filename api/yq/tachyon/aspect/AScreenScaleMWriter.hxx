////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AScreenScaleM.hpp>
#include <yq/tachyon/command/scale/AddScaleMCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleMCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScreenScaleM::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IScreenScaleM>();
        w.property(UNSAFE, "screen_scale", &AScreenScaleM::m_screenScale).tag(kTag_Save);
        w.slot(UNSAFE, &AScreenScaleM::on_set_scale);
        w.slot(UNSAFE, &AScreenScaleM::on_add_scale);
        w.slot(UNSAFE, &AScreenScaleM::on_multiply_scale);
    }
}
