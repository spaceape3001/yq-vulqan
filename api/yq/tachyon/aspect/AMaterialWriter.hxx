////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMaterial.hpp>
#include <yq/tachyon/command/SetMaterialCommand.hpp>
#include <yq/tachyon/command/SetMaterialUrlCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/asset/Material.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaterial::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMaterial>();
        w.resource("material", &AMaterial::m_material).tag(kTag_Save);

        w.slot(UNSAFE, &AMaterial::on_set_material);
        w.slot(UNSAFE, &AMaterial::on_set_material_url);
    }
}
