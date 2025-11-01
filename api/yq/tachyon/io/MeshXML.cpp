////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/core/DelayInit.hpp>
#include <yq/resource/Resource.hxx>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/xml/XmlUtils.hpp>

namespace yq::tachyon {
    namespace errors {
        using tmx_missing_root_element          = error_db::entry<"Mesh is missing root element">;
    }

    static constexpr const char*    szFormat        = "format";
    static constexpr const char*    szRoot          = "tachyon_mesh";
    static constexpr const char*    szVertex        = "vertex";
    static constexpr const char*    szFace          = "face";
    static constexpr const char*    szLine          = "line";
    static constexpr const char*    szPoint         = "point";
    static constexpr const char*    szColor         = "color";
    static constexpr const char*    szDope          = "dope";
    static constexpr const char*    szMaterial      = "material";
    static constexpr const char*    szNormal        = "normal";
    static constexpr const char*    szUV            = "uv";
    static constexpr const char*    szWeight        = "weight";
    static constexpr const char*    szTangent       = "tangent";
    
    
    Mesh*        Mesh::load_from_tmesh(const XmlDocument& doc)
    {
        const XmlNode*  root    = doc.first_node(szRoot);
        if(!root)
            return nullptr;
        return read_from_tmesh(*root);
    }
    
    Mesh*        Mesh::read_from_tmesh(const XmlNode& xml)
    {
        return nullptr;
    }
    
    ////////////////////////
    
    bool         Mesh::save_to_tmesh(const Mesh& m, XmlDocument& doc)
    {
        
        XmlNode&    root    = *(doc.create_element(szRoot));
        root.create_attribute(szFormat, "1");
        return write_to_tmesh(m, root);
    }
    
    bool         Mesh::write_to_tmesh(const Mesh& m, XmlNode& xml)
    {
        XmlDocument&    doc = *xml.document();
        auto& verts = m.mesh.vertices;
        for(size_t n=0; n<verts.size(); ++n){
            XmlNode&    vx  = *doc.create_element(szVertex);
            
            RGBA4F      clr = m.color(VERTEX, (unsigned) n);
            RGBA4F      dpe = m.dope(VERTEX, (unsigned) n);
            Vector3F    nor = m.normal(VERTEX, (unsigned) n);
            Vector3F    tgt = m.tangent(VERTEX, (unsigned) n);
            UrlView     mat = m.material(VERTEX, (unsigned) n); 
            UV2F        uv  = m.uv(VERTEX, (unsigned) n);
            
            //  write_xn(vx, verts[n]);
            
            //write_xn(vx, 
        }
        return false;
    }

    void    reg_mesh_io()
    {
        Mesh::IO::add_loader({.extensions={"tmesh"}}, Mesh::load_from_tmesh);
        Mesh::IO::add_saver({.extensions={"tmesh"}}, Mesh::save_to_tmesh);
    }
    YQ_INVOKE(reg_mesh_io();)
}
