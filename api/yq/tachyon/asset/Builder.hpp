////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {

    /*! \brief Builder of Tachyons
    
        Basically, need a template/build system for tachyons, to avoid the 
        repetion of entry.  Things can be built and/or instantiated based on 
        these.
    */
    class Builder : public Resource {
    
    public:
        std::vector<Url>    source;     //! Template/origination builders
        
        // TODO
    };
}
