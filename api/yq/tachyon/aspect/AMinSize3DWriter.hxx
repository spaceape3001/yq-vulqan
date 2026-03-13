////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMinSize3D.hpp>
#include <yq/tachyon/command/size/AddMinSize3DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize3DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize3DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize³D::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMinSize³D>();
        w.property(UNSAFE, "min_size", &AMinSize³D::m_min_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMinSize³D::on_set_min_size3);
        w.slot(UNSAFE, &AMinSize³D::on_set_min_sizeX);
        w.slot(UNSAFE, &AMinSize³D::on_set_min_sizeY);
        w.slot(UNSAFE, &AMinSize³D::on_set_min_sizeZ);

        w.slot(UNSAFE, &AMinSize³D::on_add_min_size3);
        w.slot(UNSAFE, &AMinSize³D::on_add_min_sizeX);
        w.slot(UNSAFE, &AMinSize³D::on_add_min_sizeY);
        w.slot(UNSAFE, &AMinSize³D::on_add_min_sizeZ);
        
        w.slot(UNSAFE, &AMinSize³D::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize³D::on_multiply_min_size3);
        w.slot(UNSAFE, &AMinSize³D::on_multiply_min_sizeX);
        w.slot(UNSAFE, &AMinSize³D::on_multiply_min_sizeY);
        w.slot(UNSAFE, &AMinSize³D::on_multiply_min_sizeZ);
    }
}
