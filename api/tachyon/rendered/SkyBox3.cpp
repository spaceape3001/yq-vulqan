////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SkyBox3.hpp"
#include <tachyon/logging.hpp>
#include <tachyon/asset/Shader.hpp>
#include <tachyon/api/Rendered3MetaWriter.hpp>

namespace yq::tachyon {

    VB1<glm::vec3>       SkyBox³::s_vertex = {
        { -1., -1., -1. },  // 0
        { -1., -1.,  1. },  // 1
        { -1.,  1., -1. },  // 2
        { -1.,  1.,  1. },  // 3
        {  1., -1., -1. },  // 4
        {  1., -1.,  1. },  // 5
        {  1.,  1., -1. },  // 6
        {  1.,  1.,  1. }   // 7
    };
    IB1<uint16_t>        SkyBox³::s_index = {
        //  top side
        0, 4, 6,
        6, 2, 0,
        
        // bottom side
        1, 7, 5,
        7, 1, 3,
        
        // north side
        5, 6, 4,
        6, 5, 7,
        
        // east side
        7, 2, 6,
        2, 7, 3,
        
        // south side
        3, 0, 2,
        0, 3, 1,
        
        // west side
        1, 4, 0,
        4, 1, 5
    };


    void SkyBox³::init_meta()
    {
        auto w = writer<SkyBox³>();
        w.category("Background");
        w.description("Sky Box in 3D");
        
        {
            auto& p = w.pipeline();
            p.shaders({ "assets/SkyBox3.vert", "assets/SkyBox3.frag" });
            p.vertex(SkyBox³::s_vertex, DataActivity::COMMON);
            p.index(SkyBox³::s_index, DataActivity::COMMON);
            p.topology(Topology::TriangleList);
            p.front(FrontFace::CounterClockwise);
            p.texture(&SkyBox³::m_texture, DataActivity::FIXED);
            p.push_mvp();
            
        }
    }

    SkyBox³::SkyBox³(std::initializer_list<std::string_view> szImages, const Param& p) : Rendered³(p)
    {
        if(szImages.size() == 0){
            tachyonWarning << "SkyBox³ needs IMAGES!";
            return ;
        }
        std::vector<std::string_view>       images(szImages.begin(), szImages.end());
        while(images.size() < 6)
            images.push_back(images.back());
        std::span<const std::string_view>  imageSpec(images.begin(), images.begin()+6);
        
        TextureInfo2    texInfo;
        texInfo.imageViewType       = ImageViewType::Cube;
        texInfo.addressMode         = SamplerAddressModeUVW(ALL, SamplerAddressMode::ClampToEdge);
        texInfo.compareOp           = CompareOp::Never;
        texInfo.maxAnisotropy       = 1.0;
        texInfo.layerCount          = 6;
        m_texture       = Texture::load(imageSpec, texInfo);
        //m_texture       = Texture::load(images[0], texInfo);
    }
    
    SkyBox³::~SkyBox³()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::SkyBox³)
