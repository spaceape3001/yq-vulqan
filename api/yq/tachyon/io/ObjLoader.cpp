////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ObjLoader.hpp"

#include <yq/tachyon/logging.hpp>
#include <tiny_obj_loader.h>

namespace yq::tachyon {
    tinyobj::ObjReaderSPtr     raw_load_obj(const std::filesystem::path& fp, const ObjLoadOptions& opts)
    {
        tinyobj::ObjReaderConfig    cfg;
        cfg.triangulate             = !opts.triangulate.empty();
        cfg.triangulation_method    = opts.triangulate;
        cfg.vertex_color            = opts.vertex_color;
        cfg.mtl_search_path         = opts.mtl_search_path.string();
        
        tinyobj::ObjReaderSPtr   mdl = std::make_shared<tinyobj::ObjReader>();
        if(!mdl->ParseFromFile(fp.string(), cfg)){
            tachyonWarning << "Unable to load the obj file: '" << fp << "' (" << mdl->Error() << ")";
            return {};
        }
        
        return mdl;
    }
}

