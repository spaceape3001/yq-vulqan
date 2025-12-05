////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/io/ReincarnationConfig.hpp>
#include <yq/tachyon/io/SaveData.hpp>

#include <yq/net/Url.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/StdThread.hpp>
#include <yq/tachyon/enum/SaveFlags.hpp>
#include <yq/tachyon/enum/SaveType.hpp>
#include <yq/tachyon/typedef/save.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/typedef/any_maps.hpp>
#include <yq/typedef/string_maps.hpp>
#include <variant>

namespace yq::tachyon {
    class Tachyon;
    class Delegate;

    /*! \brief Threads
    
        \note Game saving shouldn't happen until *AFTER* the application has started with all threads running. 
    *//*
        Implementation notes:
        1)  Starting with pure save/load
        2)  Will factor in the template stuff later (might need a hybrid ID system)
    */
    class Save : public Resource {
        YQ_RESOURCE_DECLARE(Save, Resource)
    public:
    
        Save();
        virtual ~Save();
        
        static void    init_meta();
        
        Save& operator<<(const Object&);
        void    add(const Object&);
        
        template <typename T>
        struct SMap {
            std::vector<T>              data;
            std::map<uint64_t,size_t>   byId;
        };
        
        SMap<DelegateSave>      delegates;
        SaveFlags               flags;
        SMap<TachyonSave>       tachyons;
        SMap<ThreadSave>        threads;
        SaveType                type = SaveType::General;
        std::vector<Url>        uses;
        
        size_t                data_size() const override;

        DelegateSave&   _delegate(const Delegate&);
        TachyonSave&    _tachyon(const Tachyon&);
        ThreadSave&     _thread(const Thread&);
        
        size_t              count(delegate_k) const;
        size_t              count(tachyon_k) const;
        size_t              count(thread_k) const;
        
        const DelegateSave* delegate(uint64_t) const;
        const TachyonSave*  tachyon(uint64_t) const;
        const ThreadSave*   thread(uint64_t) const;
        
        void                    renumerate();

        /*! \brief Executes the save to create new tachyons
        
            \note This one does not schedule the tachyons onto any threads... that's left 
            to the caller
        */
        std::error_code         execute(TachyonPtrVector&, const ReincarnationConfig&cfg={}) const;
        
        /*! \brief Executes the save to create & schedule new tachyons
        */
        std::error_code         execute(schedule_k, const ReincarnationConfig&cfg={}, TachyonIDSet* pIDs=nullptr) const;
        
        struct Reincarnator;
    };
}
