////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/aspect/AColorProfile.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileCommand.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileSpecCommand.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileUrlCommand.hpp>

namespace yq::tachyon {
    template <typename C>
    void AColorProfile::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IColorProfile>();
        w.resource("color_profile", &AColorProfile::m_colorProfile).tag(kTag_Save);

        w.slot(UNSAFE, &AColorProfile::on_set_color_profile);
        w.slot(UNSAFE, &AColorProfile::on_set_color_profile_spec);
        w.slot(UNSAFE, &AColorProfile::on_set_color_profile_url);
    }
}
