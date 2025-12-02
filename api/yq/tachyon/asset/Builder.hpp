////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {

    struct Def {
        std::string                                 className;  //< full thing, unambigous (well, as much as a string can be)
        std::multimap<std::string,Any>              properties;
        
        //  internal *STATE* goes here too
    };
    
    struct ResourceDef : public Def {
    };
    
    struct DelegateDef : public Def {
    };
    
    struct TachyonDef : public Def {
        StdThread                                   thread = StdThread::Auto;
        std::vector<std::string>                    children;
        std::multimap<std::string,DelegateDef>      delegates;
        std::multimap<std::string,ResourceDef>      resources;
        // aspects...
        
    };

    /*! \brief Builder of Tachyons
    
        Basically, need a template/build system for tachyons, to avoid the 
        repetion of entry.  Things can be built and/or instantiated based on 
        these.
    */
    class Builder  /* Save??? */ : public Resource {
    
    public:
        std::vector<Url>                            source;         //! Template/origination builders
        std::map<std::string,Any>                   parameters;     //!< Our parameters (useful for others)
        std::multimap<std::string,std::string>      pbinder;        //!< Name/Key of parameter locations (it'll be a/b/c#prop format).
        std::vector<TachyonDef>                     tachyons;       //!< All tachyons that are part of this builder
        std::map<std::string,ResourceDef>           resources;      //!< Any needed resources (non URLed?)
    };
}
