////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/container/EnumMap.hpp>
#include <yq/core/Object.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/Type.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/api/types.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
#include <yq/tachyon/typedef/clock.hpp>
#include <yq/tachyon/typedef/collision.hpp>
#include <yq/tachyon/typedef/controller.hpp>
#include <yq/tachyon/typedef/cursor.hpp>
#include <yq/tachyon/typedef/desktop.hpp>
#include <yq/tachyon/typedef/engine.hpp>
#include <yq/tachyon/typedef/frame.hpp>
#include <yq/tachyon/typedef/gamepad.hpp>
#include <yq/tachyon/typedef/graphics_card.hpp>
#include <yq/tachyon/typedef/group.hpp>
#include <yq/tachyon/typedef/joystick.hpp>
#include <yq/tachyon/typedef/keyboard.hpp>
#include <yq/tachyon/typedef/kinetic.hpp>
#include <yq/tachyon/typedef/kinetic3.hpp>
#include <yq/tachyon/typedef/layer.hpp>
#include <yq/tachyon/typedef/light.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tachyon/typedef/manager.hpp>
#include <yq/tachyon/typedef/master.hpp>
#include <yq/tachyon/typedef/model.hpp>
#include <yq/tachyon/typedef/monitor.hpp>
#include <yq/tachyon/typedef/mouse.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yq/tachyon/typedef/physics.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/scene3.hpp>
#include <yq/tachyon/typedef/spatial.hpp>
#include <yq/tachyon/typedef/spatial2.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yq/tachyon/typedef/window.hpp>

#include <yq/tachyon/logging.hpp>


#include <chrono>
#include <functional>
#include <unordered_map>
#include <set>

namespace yq { class Stream; }

#ifdef foreach
    #undef foreach
#endif

namespace yq::tachyon {
    class Proxy;
    class InterfaceMeta;
    class Tasker;
    class ViProcessor;

    /*
        Tachyons will *belong* to a thread... either directly or indirectly 
        (ie a chain).  During some threads execution (ie, sim-thread or viz-thread), 
        these may be temporarily delegated into other threads, but will not strip 
        the owning thread of ownership.
    */
    
    struct TachyonFrame;

    class Frame : public Object, public RefCount {
        YQ_OBJECT_DECLARE(Frame, Object)        // to access the meta capabilities
    public:
    
        using KeyToIDMap    = std::multimap<std::string,uint64_t,IgCase>;
    
        //! Returns the current "published" frame for this thread 
        //! \note This may be null, so check!
        static const Frame*     current() { return s_current; }
    
        static TypedID  resolve(TachyonSpec);
    
        using proxy_span_t  = std::span<Proxy* const>;

        std::span<const TypedID>    children(TachyonID) const;
        
        bool contains(Type, uint64_t) const;
        bool contains(TypedID) const;
        
        template <typename T>
        bool contains(ID<T> id) const 
        {
            if constexpr (std::is_same_v<T,Tachyon>){
                return m_allIds.contains(id);
            } else
                return contains(type_v<T>, id.id);
        }
        
        template <typename T=Tachyon>
        size_t count() const
        {
            if constexpr (std::is_same_v<T,Tachyon>){
                return m_allIds.size();
            } else {
                return count(type_v<T>);
            }
        }
        
        size_t count(Type) const;
        size_t count(tachyon_k) const;
        size_t count(children_k, TachyonID) const;
        const TachyonData*                  data_of(Type, uint64_t) const;
        const TachyonData*                  data_of(TachyonID) const;
    
        template <typename T>
        const data_t<T>*                    data(const ID<T>& id) const
        {
            if constexpr (std::is_same_v<T,Tachyon>){
                return data_of({id.id});
            } else {
                return static_cast<const data_t<T>*>(data_of(type_v<T>,id.id));
            }
        }
        
        const TachyonData*                  data(TypedID tid) const
        {
            return data_of({tid});
        }
        
        TachyonID                           first_of(Type) const;
        TachyonID                           first_of(tachyon_k) const;
        
        template <typename T>
        ID<T>                               first() const
        {
            if constexpr (std::is_same_v<T,Tachyon>){
                return first_of(TACHYON);
            } else
                return (ID<T>) first_of(type_v<T>);
        }
        
        template <typename C, typename Pred>
        void        foreach(ptr_k, std::span<const TypedID> ids, Pred&& pred) const;
        
        template <typename C, typename Pred>
        void        foreach(ref_k, std::span<const TypedID> ids, Pred&& pred) const;
        
        template <typename Pred>
        void        foreach(child_k, TachyonID, Pred&& pred) const;

        template <typename Pred>
        void        foreach(child_k, recursive_k, TachyonID, Pred&& pred) const;
        
        template <typename T=Tachyon>
        const std::set<ID<T>>&              ids() const
        {
            if constexpr (std::is_same_v<T,Tachyon>){
                return m_allIds;
            } else {
                return reinterpret_cast<const std::set<ID<T>>&>(ids_of(type_v<T>));
            }
        }
        
        const std::set<TachyonID>&          ids_of(Type) const;
        
        const TachyonMeta*                  meta_of(Type, uint64_t) const;
        const TachyonMeta*                  meta_of(TachyonID) const;
        
        template <typename T>
        const meta_t<T>*                    meta(ID<T> id) const
        {
            if constexpr (std::is_same_v<T,Tachyon>){
                return meta_of({id.id});
            } else {
                return static_cast<const meta_t<T>*>( meta_of(type_v<T>, id));
            }
        }
        
        const TachyonMeta*                  meta(const TypedID tid) const
        {
            return meta_of(tid);
        }

        Tachyon*                            object_of(Type, uint64_t) const;
        Tachyon*                            object_of(TachyonID) const;
        
        template <typename T>
        T*  object(ID<T> id) const
        {
            if constexpr (std::is_same_v<T,Tachyon>){
                return object_of({id.id});
            } else {
                return static_cast<T*>(object_of(type_v<T>, id.id));
            }
        }
        
        Tachyon* object(TypedID tid) const
        {
            return object_of({tid.id});
        }

        Tachyon*                            object(parent_k, TachyonID) const;
        Tachyon*                            object(root_k, TachyonID) const;

        ThreadID                            owner(TachyonID) const;
        TypedID                             parent(TachyonID) const;

        //! First parent of type (ie, may skip
        TypedID                             parent(Type, TachyonID) const;


        proxy_span_t                        proxies(TachyonID) const;
        
        /*! \brief Gets the specific proxy
        
            This will get the specific proxy, if it exists.  
            Practically, this will be okay to call once a tick for a specific 
            tachyon/interface need, however, it should be cached for the rest
            of the tick (if practical). 
            
            \note DON'T GO WILD, ONLY CALL FOR NECESSARY INTERFACES ON DEMAND
        */
        template <typename P>
        P*                                  proxy(TachyonID) const;

        Proxy*                              proxy(TachyonID, const InterfaceMeta&) const;
        
        //! Gets the root tachyon of this chain
        //! \note It'll return wherever the tree stops in this frame (ie, missing snapshot)
        //! \note Root *may* be itself for the case of no-parent
        TypedID                             root(TachyonID) const;
        
        //! Gets the upper most tachyon of given type
        //! \note If specified tachyon *fits*, it'll be returned
        TypedID                             root(Type, TachyonID) const;

        
        const TachyonSnap*                  snap_of(Type, uint64_t) const;
        const TachyonSnap*                  snap_of(TachyonID) const;

        template <typename T>
        const snap_t<T>*                    snap(ID<T> id) const
        {
            if constexpr (std::is_same_v<T,Tachyon>){
                return snap_of({id});
            } else {
                return static_cast<const snap_t<T>*>(snap_of(type_v<T>, id));
            }
        }
        
        const TachyonSnap*      snap(TypedID id) const
        {
            return snap_of({id.id});
        }

        Types           types(TachyonID) const;
        TypedID         typed(TachyonID) const;
        
        TypedID         typed(StdThread) const;

        ThreadID        origin() const { return m_origin; }
        uint64_t        number() const { return m_number; }
        time_point_t    wallclock() const { return m_wallclock; }
        uint64_t        tick() const { return m_tick; }
        
        //! Note this can be modified by commands!
        unit::Second    time() const { return m_time; }
        
        void            report(Stream&) const;

        static void init_meta();

    private:
        void add(ThreadID, const TachyonFrame&);

        static thread_local const Frame*                            s_current;

        static std::atomic<uint64_t>                                s_lastId;

        const ThreadID          m_origin;
        const uint64_t          m_number;
        const time_point_t      m_wallclock;
        const uint64_t          m_tick;
        const unit::Second      m_time;
        
                                                                    
        struct TBit {
            ThreadID                owner;
            TypedID                 typedId;
            Ref<Tachyon>            object;
            Ref<const TachyonData>  data;
            Ref<const TachyonSnap>  snap;
        };
        
        using id_set_t = std::set<TachyonID>;
        
        std::unordered_map<uint64_t,TBit>                           m_data;
        EnumMap<Type, std::set<TachyonID>>                          m_idsByType;
        std::set<TachyonID>                                         m_allIds;
        

        friend class Thread;
        friend class Tasker;
        friend FramePtr;
        friend FrameCPtr;
        friend class ViProcessor;

        Frame(ThreadID, uint64_t, unit::Second);
        virtual ~Frame();
        
        struct Builder;
    
        Frame(const Frame&) = delete;
        Frame(Frame&&) = delete;
        Frame& operator=(const Frame&) = delete;
        Frame& operator=(Frame&&) = delete;
        
    };

    template <typename Pred>
    void    Frame::foreach(child_k, TachyonID tac, Pred&& pred) const
    {
        for(TypedID typed : children(tac)){
            pred(typed);
        }
    }

    template <typename Pred>
    void    Frame::foreach(child_k, recursive_k, TachyonID tac, Pred&& pred) const
    {
        for(TypedID typed : children(tac)){
            pred(typed);
            foreach(CHILD, RECURSIVE, typed, pred);
        }
    }

    template <typename C, typename Pred>
    void    Frame::foreach(ptr_k, std::span<const TypedID> ids, Pred&& pred) const
    {
        for(const TypedID& t : ids){
            C*  c   = dynamic_cast<C*>(object(t));
            if(c){
                pred(c);
            }
        }
    }

    template <typename C, typename Pred>
    void    Frame::foreach(ref_k, std::span<const TypedID> ids, Pred&& pred) const
    {
        for(const TypedID& t : ids){
            C*  c   = dynamic_cast<C*>(object(t));
            if(c){
                pred(*c);
            }
        }
    }

    template <typename C>
    C*      Frame::proxy(TachyonID tid) const
    {
        for(Proxy* p : proxies(tid)){
            if(C* c = dynamic_cast<C*>(p)){
                return c;
            }
        }

        return nullptr;
    }
}
