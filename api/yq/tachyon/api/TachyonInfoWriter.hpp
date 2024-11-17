////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaObjectInfoWriter.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {
    template <SomeTachyon C, SomePost P>
    class PBXDispatch_VoidCRef : public PBXDispatch {
    public:
        typedef void (C::*FN)(const P&);
        FN              m_fn;
        
        PBXDispatch_VoidCRef(FN fn) : PBXDispatch(), m_fn(fn)
        {
            m_tachyon   = &meta<C>();
            m_post      = &meta<P>();
        }
        
        bool  dispatch(Tachyon &tac, const PostCPtr& pp) const override
        {
            C&  c   = static_cast<C&>(tac);
            (c.*m_fn)(static_cast<const P&>(*pp));
            return true;
        }

        const char* debug_string() const override
        {
            return "void(C::*)(const P&)";
        }
    };
    
    template <SomeTachyon C, SomePost P>
    class PBXDispatch_BoolCRef : public PBXDispatch {
    public:
        typedef bool (C::*FN)(const P&);
        FN              m_fn;
        
        PBXDispatch_BoolCRef(FN fn, const TriggerCPtr& trigger, MismatchPolicy mp) : PBXDispatch(trigger, mp), m_fn(fn)
        {
            m_tachyon   = &meta<C>();
            m_post      = &meta<P>();
        }
        
        bool  dispatch(PBX &pbx, const PostCPtr& pp) const override
        {
            C&  c   = static_cast<C&>(pbx);
            return (c.*m_fn)(static_cast<const P&>(*pp));
        }

        const char* debug_string() const override
        {
            return "bool(C::*)(const P&)";
        }
    };
    
    template <SomeTachyon C, SomePost P>
    class PBXDispatch_VoidCPtr : public PBXDispatch {
    public:
        typedef void (C::*FN)(const Ref<const P>&);
        FN              m_fn;
        
        PBXDispatch_VoidCPtr(FN fn, const TriggerCPtr& trigger, MismatchPolicy mp) : PBXDispatch(trigger, mp), m_fn(fn)
        {
            m_tachyon   = &meta<C>();
            m_post      = &meta<P>();
        }
        
        bool  dispatch(PBX &pbx, const PostCPtr& pp) const override
        {
            C&  c   = static_cast<C&>(pbx);
            Ref<const P>    ppp(static_cast<const P*>(pp.ptr()));
            (c.*m_fn)(ppp);
            return true;
        }

        const char* debug_string() const override
        {
            return "void(C::*)(const Ref<P>&)";
        }
    };

    template <SomeTachyon C, SomePost P>
    class PBXDispatch_BoolCPtr : public PBXDispatch {
    public:
        typedef bool (C::*FN)(const Ref<const P>&);
        FN              m_fn;
        
        PBXDispatch_BoolCPtr(FN fn, const TriggerCPtr& trigger, MismatchPolicy mp) : PBXDispatch(trigger, mp), m_fn(fn)
        {
            m_tachyon   = &meta<C>();
            m_post      = &meta<P>();
        }
        
        bool  dispatch(PBX &pbx, const PostCPtr& pp) const override
        {
            C&  c   = static_cast<C&>(pbx);
            Ref<const P>    ppp(static_cast<const P*>(pp.ptr()));
            return (c.*m_fn)(ppp);
        }

        const char* debug_string() const override
        {
            return "bool(C::*)(const Ref<P>&)";
        }
    };

    class PBXDispatch::Writer {
    public:
        Writer(PBXDispatch* pbx=nullptr) : m_pbx(pbx) {}
        
        Writer& name(std::string_view v) 
        {
            if(m_pbx){
                m_pbx -> m_name = v;
            }
            return *this;
        }
        
    private:
        PBXDispatch*    m_pbx;
    };


    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////


    /*! \brief Writer of manager information
    */
    template <typename C>
    class TachyonInfo::Writer : public MetaObjectInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(TachyonInfo* theInfo) : MetaObjectInfo::Writer<C>(theInfo), m_meta(theInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(TachyonInfo& theInfo) : Writer(&theInfo)
        {
        }

        template <SomePost P, SomePBX C2=C>
        void    slot(void (C::*fn)(const P&))
        {
            static_assert(std::derived_from<C,C2>, "Incompatible Tachyon types, need inheritance");
            if(m_meta && Meta::thread_safe_write()){
                PBXDispatch*    ret = new PBXDispatch_VoidCRef<C2,P>(fn, trigger, mp);
                m_meta -> add_dispatch(ret);
                return ret;
            }
            return {};
        }
        
        template <SomePost P, SomePBX C2=C>
        void    slot(bool (C::*fn)(const P&))
        {
            static_assert(std::derived_from<C,C2>, "Incompatible Tachyon types, need inheritance");
            if(m_meta && Meta::thread_safe_write()){
                PBXDispatch*    ret = new PBXDispatch_BoolCRef<C2,P>(fn, trigger, mp);
                m_meta -> add_dispatch(ret);
                return ret;
            }
            return {};
        }
        
        
        template <SomePost P, SomePBX C2=C>
        void    slot(void (C::*fn)(const Ref<const P>&))
        {
            static_assert(std::derived_from<C,C2>, "Incompatible Tachyon types, need inheritance");
            if(m_meta && Meta::thread_safe_write()){
                PBXDispatch*    ret = new PBXDispatch_VoidCPtr<C2,P>(fn, trigger, mp);
                m_meta -> add_dispatch(ret);
                return ret;
            }
            return {};
        }
        
        template <SomePost P, SomePBX C2=C>
        void    slot(bool (C::*fn)(const Ref<const P>&))
        {
            static_assert(std::derived_from<C,C2>, "Incompatible Tachyon types, need inheritance");
            if(m_meta && Meta::thread_safe_write()){
                PBXDispatch*    ret = new PBXDispatch_BoolCPtr<C2,P>(fn, trigger, mp);
                m_meta -> add_dispatch(ret);
                return ret;
            }
            return {};
        }
        

        template <Interface I>
        void    interface<I>
        {
            if(m_meta){
                m_meta -> add_interface(&meta<I>());
            }
        }
        
    private:
        TachyonInfo* m_meta;
    };
}
