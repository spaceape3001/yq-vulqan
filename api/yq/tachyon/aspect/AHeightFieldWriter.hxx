////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/aspect/AHeightField.hpp>
#include <yq/tachyon/command/height_field/SetHeightFieldCommand.hpp>
#include <yq/tachyon/command/height_field/SetHeightFieldSpecCommand.hpp>
#include <yq/tachyon/command/height_field/SetHeightFieldUrlCommand.hpp>

namespace yq::tachyon {
    template <typename C>
    void AHeightField::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IHeightField>();
        w.resource("height_field", &AHeightField::height_field_get).setter(&AHeightField::height_field_set).tag(kTag_Save);

        w.slot(UNSAFE, &AHeightField::on_set_height_field);
        w.slot(UNSAFE, &AHeightField::on_set_height_field_spec);
        w.slot(UNSAFE, &AHeightField::on_set_height_field_url);
    }
}
