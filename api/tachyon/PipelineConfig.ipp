////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PipelineConfig.hpp"
#include <tachyon/Shader.hpp>
#include <yq/basic/Logging.hpp>
#include <yq/meta/TypeInfo.hpp>

namespace yq::tachyon {
    PipelineConfig::PipelineConfig() = default;
    PipelineConfig::~PipelineConfig() = default;

    namespace {
        log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&log, const VBOAttr& attr)
        {
            log << attr.location << "/" << attr.offset << ": ";
            if(attr.type)
                log << attr.type->name() << " ";
            log << attr.format.key();
            return log;
        }
    }
    
    log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&log, const PipelineConfig& pc)
    {
        log << "Pipeline ";
        if(pc.object){
            log << pc.object->name();
        } else {
            log << "(unattached)";
        }
        log << "." << pc.role << " {\n";
        
        log << "  Topology     : " << pc.topology.key() << "\n";
        log << "  Polygon Mode : " << pc.polymode.key() << "\n";
        log << "  Front Face   : " << pc.front.key() << "\n";
        log << "  Culling Mode : " << pc.culling.key() << "\n";
        log << "  Binding      : " << pc.binding.key() << "\n";
        //log << "  Push         : " << pc.push.type.key() << "\n";
        log << "  Push Bytes   : " << pc.push.size << "\n";
        
        log << "  Shaders      : " << pc.shaders.size() << "\n";
        for(const ShaderSpec& ss : pc.shaders)
            log << "  > " << Shader::name(ss) << "\n";
        log << "  VBOs         : " << pc.vbos.size() << "\n";
        for(const VBOConfig& vbo : pc.vbos){
            log << "  > " << vbo.activity.key() << " " << vbo.stride << " " << vbo.inputRate.key() << "\n";
            for(const VBOAttr& vba : vbo.attrs)
                log << "  ... " << vba << "\n";
        }
        
        log << "  IBOs         : " << pc.ibos.size() << "\n";
        for(const IBOConfig& ibo : pc.ibos)
            log << "  > " << ibo.activity.key() << " " << ibo.type.key() << "\n";
        
        log << "  UBOs         : " << pc.ubos.size() << "\n";
        log << "  Textures     : " << pc.texs.size() << "\n";
        return log;
    }
    
}
