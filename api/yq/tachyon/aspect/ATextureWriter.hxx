////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/aspect/ATexture.hpp>
#include <yq/tachyon/command/texture/SetTextureCommand.hpp>
#include <yq/tachyon/command/texture/SetTextureSpecCommand.hpp>
#include <yq/tachyon/command/texture/SetTextureUrlCommand.hpp>

namespace yq::tachyon {
    template <typename C>
    void ATexture::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ITexture>();
        w.resource("texture", &ATexture::m_texture).tag(kTag_Save);

        w.slot(UNSAFE, &ATexture::on_set_texture);
        w.slot(UNSAFE, &ATexture::on_set_texture_spec);
        w.slot(UNSAFE, &ATexture::on_set_texture_url);
    }
}
