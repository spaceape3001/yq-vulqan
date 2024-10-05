////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {

    class Painter {
    public:
    
        Painter();
        Painter(DataFormat, std::initializer_list<uint32_t> dims);
        Painter(std::shared_ptr<Pixmap>);
        Painter(Pixmap&);
        
    private:
        Pixmap*                     m_pixmap;
        std::shared_ptr<Pixmap>     m_pixmapData;
    };

}
