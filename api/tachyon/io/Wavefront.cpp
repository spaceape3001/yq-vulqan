////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Wavefront.hpp"
#include "WavefrontIO.hpp"
#include <yq/container/vector_utils.hpp>
#include <yq/text/chars.hpp>
#include <yq/text/parse.hpp>
#include <yq/text/vsplit.hpp>
#include <yq/text/transform.hpp>
#include <tachyon/errors.hpp>
#include <tachyon/logging.hpp>

static bool operator|=(std::error_code& a, const std::error_code& b)
{
    if(a != std::error_code())
        return false;
    if(b == std::error_code())
        return true;
    a   = b;
    return false;
}

namespace yq::tachyon::wavefront {
    
    namespace errors {
        using namespace yq::errors;
        using namespace yq::tachyon::errors;
        
        using bad_obj_command_error                 = error_db::entry<"command not recognized">;
        using empty_group_name                      = error_db::entry<"empty group name">;
        using empty_obj_name                        = error_db::entry<"empty object name">;
        using empty_material_file_name              = error_db::entry<"empty material file name">;
        using empty_smooting_group_name             = error_db::entry<"empty smoothing group name">;
        using empty_use_material_name               = error_db::entry<"empty use material name">;
        using insufficient_normal_arguments         = error_db::entry<"insufficient normal coordinate arguments">;
        using insufficient_parameterized_arguments  = error_db::entry<"insufficient parameterized vertex arguments">;
        using insufficient_texture_arguments        = error_db::entry<"insufficient texture coordinate arguments">;
        using insufficient_vertex_arguments         = error_db::entry<"insufficient vertex arguments">;
        using obj_parsing_error                     = error_db::entry<"error parsing OBJ file">;
        using missing_face_vertex_argument          = error_db::entry<"vertex unspecified in polygon face">;
        using too_many_normal_arguments             = error_db::entry<"too many vertex normal arguments">;
        using too_many_parameterized_arguments      = error_db::entry<"too many parameterized vertex arguments">;
        using too_many_texture_arguments            = error_db::entry<"too many texture coordinate arguments">;
        using too_many_vertex_arguments             = error_db::entry<"too many vertex arguments">;
        using too_many_vertex_spec_arguments        = error_db::entry<"too many vertex specification arguments">;
    }


    static std::error_code     parse(GeometryVertex& ret, std::string_view arg)
    {
        std::error_code ec;
        size_t  cnt = 0;
        vsplit(arg, ' ', [&](std::string_view v){
            if(v.empty())
                return;
            double_x    val = to_double(v);
            if(!val){
                ec  |= val.error();
                return;
            }
            ++cnt;
            if(is_nan(ret.point.x)){
                ret.point.x = *val;
            } else if(is_nan(ret.point.y)){
                ret.point.y = *val;
            } else if(is_nan(ret.point.z)){
                ret.point.z = *val;
            } else if(is_nan(ret.point.w)){
                ret.point.w = *val;
            } else {
                ec  = errors::too_many_vertex_arguments();
            }
        });
        if(cnt < 2)
            ec |= errors::insufficient_vertex_arguments();
        return ec;
    }
    
    static std::error_code     parse(TextureCoordinate&ret, std::string_view arg)
    {
        std::error_code ec;
        size_t  cnt = 0;
        vsplit(arg, ' ', [&](std::string_view v){
            if(v.empty())
                return;
            double_x    val = to_double(v);
            if(!val){
                ec  |= val.error();
                return;
            }
            ++cnt;
            if(is_nan(ret.uvw.u)){
                ret.uvw.u = *val;
            } else if(is_nan(ret.uvw.v)){
                ret.uvw.v = *val;
            } else if(is_nan(ret.uvw.w)){
                ret.uvw.w = *val;
            } else {
                ec  = errors::insufficient_texture_arguments();
            }
        });
        if(cnt < 1)
            ec |= errors::insufficient_vertex_arguments();
        return ec;
    }
    
    static std::error_code     parse(VertexNormal&ret, std::string_view arg)
    {
        std::error_code ec;
        size_t  cnt = 0;
        vsplit(arg, ' ', [&](std::string_view v){
            if(v.empty())
                return;
            double_x    val = to_double(v);
            if(!val){
                ec  |= val.error();
                return;
            }
            ++cnt;
            if(is_nan(ret.normal.x)){
                ret.normal.x = *val;
            } else if(is_nan(ret.normal.y)){
                ret.normal.y = *val;
            } else if(is_nan(ret.normal.z)){
                ret.normal.z = *val;
            } else {
                ec  = errors::too_many_normal_arguments();
            }
        });
        if(cnt < 2)
            ec |= errors::insufficient_normal_arguments();
        return ec;
    }
    
    static std::error_code     parse(VertexSpec&ret, std::string_view arg)
    {
        std::error_code ec;
        size_t          n = 0;
        vsplit(arg, '/', [&](std::string_view v){
            if(arg.empty() && !n){
                ec |= errors::missing_face_vertex_argument();
                return;
            }
            if(!arg.empty()){
                int_x   val = to_integer(v);
                if(!val){
                    ec |= val.error();
                    return;
                }
                switch(n){
                case 0:
                    ret.vertex  = *val;
                    break;
                case 1:
                    ret.texc    = *val;
                    break;
                case 2:
                    ret.normal  = *val;
                    break;
                default:
                    ec  |= errors::too_many_vertex_spec_arguments();
                    break;
                }
            }
            
            ++n;
        });

        return ec;
    }
    
    static std::error_code     parse(PolygonFace& ret, std::string_view arg)
    {
        std::error_code ec;
        vsplit(arg, ' ', [&](std::string_view v){
            if(v.empty())
                return;
            VertexSpec  vs;
            if(ec |= parse(vs, v))
                ret.vertices.push_back(vs);
        });
        return ec;
    }
    
    static std::error_code     parse(LineElement& ret, std::string_view arg)
    {
        std::error_code ec;
        vsplit(arg, ' ', [&](std::string_view v){
            if(v.empty())
                return;
            int_x   val = to_integer(v);
            if(!val){
                ec |= val.error();
                return;
            }
            
            ret.vertices.push_back(*val);
        });
        return errors::todo();
    }
    
    static std::error_code     parse(ParameterizedVertex&ret, std::string_view arg)
    {
        std::error_code ec;
        size_t  cnt = 0;
        vsplit(arg, ' ', [&](std::string_view v){
            if(v.empty())
                return;
            double_x    val = to_double(v);
            if(!val){
                ec  |= val.error();
                return;
            }
            ++cnt;
            if(is_nan(ret.vertex.u)){
                ret.vertex.u = *val;
            } else if(is_nan(ret.vertex.v)){
                ret.vertex.v = *val;
            } else if(is_nan(ret.vertex.w)){
                ret.vertex.w = *val;
            } else {
                ec  = errors::insufficient_parameterized_arguments();
            }
        });
        if(cnt < 1)
            ec |= errors::insufficient_parameterized_arguments();
        return ec;
    }
    

    std::error_code     parse_object_data(ObjFileData&ret, std::string_view file)
    {
        std::error_code     ec, res;
        size_t              linenum = 0;
        
        vsplit(file, '\n', [&](std::string_view line){
            if(res != std::error_code())
                return;
                
            ++linenum;
            line    = trimmed(line);
            if(line.empty()){
                ret.lines.push_back(BlankLine());
                return;
            }
            
            if(line[0] == '#'){
                ret.lines.push_back(Comment(std::string(trimmed(line.substr(1)))));
                return;
            }

            auto cmdend = line.find_first_of(' ');
            if(cmdend == std::string_view::npos)
                return;
            
            auto cmd    = line.substr(0,cmdend);
            auto args   = trimmed(line.substr(cmdend));
            
            if(cmd == "v"){   //  vertex
                GeometryVertex      ins;
                if(ec |= parse(ins, args))
                    ret.lines.push_back(ins);
            } else if(cmd == "vt"){   // texture coordinate
                TextureCoordinate   ins;
                if(ec |= parse(ins, args))
                    ret.lines.push_back(ins);
            } else if(cmd == "vp"){   // parameterized vertex
                ParameterizedVertex ins;
                if(ec |= parse(ins, args))
                    ret.lines.push_back(ins);
            } else if(cmd == "vn"){
                VertexNormal    ins;
                if(ec |= parse(ins, args))
                    ret.lines.push_back(ins);
            } else if(cmd == "f"){    // polygon face
                PolygonFace ins;
                if(ec |= parse(ins, args))
                    ret.lines.push_back(ins);
            } else if(cmd == "l"){    // line string
                LineElement ins;
                if(ec |= parse(ins, args))
                    ret.lines.push_back(ins);
            } else if(cmd == "o"){    // object name tag
                if(args.empty()){
                    ec = errors::empty_obj_name();
                } else
                    ret.lines.push_back(ObjectName( std::string(args) ));
            } else if(cmd == "g"){    // polygon group
                if(args.empty()){
                    ec = errors::empty_group_name();
                } else
                    ret.lines.push_back(PolygonGroup{ std::string(args) });
            } else if(cmd == "s"){    // smoothing group
                if(args.empty()){
                    ec  = errors::empty_smooting_group_name();
                } else {
                    ret.lines.push_back(SmoothingGroup{ std::string(args) });
                }
            } else if(cmd == "mtllib"){
                if(args.empty()){
                    ec  = errors::empty_material_file_name();
                } else {
                    ret.lines.push_back(MaterialLibrary{ std::string(args) });
                }
            } else if(cmd == "usemtl"){
                if(args.empty()){
                    ec  = errors::empty_use_material_name();
                } else {
                    ret.lines.push_back(UseMaterial{ std::string(args) });
                }
            } else if(cmd == "deg"){
                ec = errors::todo();
            } else if(cmd == "bmat"){
                ec  = errors::todo();
            } else if(cmd == "step"){
                ec  = errors::todo();
            } else if(cmd == "cstype"){
                ec  = errors::todo();
            } else if(cmd == "curv"){
                ec  = errors::todo();
            } else if(cmd == "curv2"){
                ec  = errors::todo();
            } else if(cmd == "surf"){
                ec  = errors::todo();
            } else if(cmd == "parm"){
                ec  = errors::todo();
            } else if(cmd == "trim"){
                ec  = errors::todo();
            } else if(cmd == "hole"){
                ec  = errors::todo();
            } else if(cmd == "scrv"){
                ec  = errors::todo();
            } else if(cmd == "sp"){
                ec  = errors::todo();
            } else if(cmd == "end"){
                ec  = errors::todo();
            } else if(cmd == "con"){
                ec  = errors::todo();
            } else if(cmd == "mg"){
                ec  = errors::todo();
            } else if(cmd == "bevel"){
                ec  = errors::todo();
            } else if(cmd == "c_interp"){
                ec  = errors::todo();
            } else if(cmd == "d_interp"){
                ec  = errors::todo();
            } else if(cmd == "lod"){
                ec  = errors::todo();
            } else if(cmd == "shadow_obj"){
                ec  = errors::todo();
            } else if(cmd == "trace_obj"){
                ec  = errors::todo();
            } else if(cmd == "ctech"){
                ec  = errors::todo();
            } else if(cmd == "stech"){
                ec  = errors::todo();
            } else {
                ec = errors::bad_obj_command_error();
            }
            
            if(ec != std::error_code()){
                tachyonWarning << "Wavefront parsing (line " << linenum << "): " << ec.message();
                res |= ec;
                ec  = {};
            }
        });
        
        return res;
    }
    
    //std::error_code     write_object_data(Stream&, const ObjFileData&);

}
