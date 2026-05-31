////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Frame.hpp"

#include <yq/tachyon/api/Controller.hpp>
#include <yq/tachyon/api/ControllerData.hpp>
#include <yq/tachyon/api/FrameBuilder.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/api/ManagerData.hpp>
//#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>

#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Camera3Data.hpp>
#include <yq/tachyon/api/Group.hpp>
#include <yq/tachyon/api/GroupData.hpp>

#include <yq/tachyon/api/Kinetic3.hpp>
#include <yq/tachyon/api/Kinetic3Data.hpp>

#include <yq/tachyon/api/Layer.hpp>
#include <yq/tachyon/api/LayerData.hpp>
#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/api/Light3Data.hpp>
#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/api/PhysicsData.hpp>

#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/Rendered3Data.hpp>
#include <yq/tachyon/api/Scene3.hpp>
#include <yq/tachyon/api/Scene3Data.hpp>
#include <yq/tachyon/api/Spatial2.hpp>
#include <yq/tachyon/api/Spatial2Data.hpp>
#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/api/Spatial3Data.hpp>

#include <yq/tachyon/app/Engine.hpp>
#include <yq/tachyon/app/EngineData.hpp>
#include <yq/tachyon/app/Master.hpp>
#include <yq/tachyon/app/MasterData.hpp>
#include <yq/tachyon/app/Viewer.hpp>
#include <yq/tachyon/app/ViewerData.hpp>

#include <yq/tachyon/os/Cursor.hpp>
#include <yq/tachyon/os/CursorData.hpp>
#include <yq/tachyon/os/Desktop.hpp>
#include <yq/tachyon/os/DesktopData.hpp>
#include <yq/tachyon/os/Gamepad.hpp>
#include <yq/tachyon/os/GamepadData.hpp>
#include <yq/tachyon/os/GraphicsCard.hpp>
#include <yq/tachyon/os/GraphicsCardData.hpp>
#include <yq/tachyon/os/Joystick.hpp>
#include <yq/tachyon/os/JoystickData.hpp>
#include <yq/tachyon/os/Keyboard.hpp>
#include <yq/tachyon/os/KeyboardData.hpp>
#include <yq/tachyon/os/Monitor.hpp>
#include <yq/tachyon/os/MonitorData.hpp>
#include <yq/tachyon/os/Mouse.hpp>
#include <yq/tachyon/os/MouseData.hpp>
#include <yq/tachyon/os/Window.hpp>
#include <yq/tachyon/os/WindowData.hpp>

//#include <yq/tachyon/api/Editor.hpp>
//#include <yq/tachyon/api/EditorData.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/api/WidgetData.hpp>

#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/CameraData.hpp>
#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/api/LightData.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/SceneData.hpp>

#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/SpatialData.hpp>

#include <yq/core/Enumeration.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/meta/ObjectMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Frame)

namespace yq::tachyon {
    void Frame::init_meta()
    {
        auto w = writer<Frame>();
        w.description("Tachyon Frame");
        w.abstract();
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    std::atomic<uint64_t>      Frame::s_lastId{0};
    thread_local const Frame*  Frame::s_current = nullptr;

    TypedID  Frame::resolve(TachyonSpec ts)
    {
        if(auto p = std::get_if<TypedID>(&ts))
            return *p;
        
        if(auto p = std::get_if<TachyonID>(&ts)){
            if(s_current)
                return s_current -> typed(*p);
        }
        return {};
    }

    ////////////////////////////////////////////////////////////////////////////
    
    Frame::Frame(ThreadID th, uint64_t ti, unit::Second now) : 
        m_origin(th), m_number(++s_lastId), m_wallclock(clock_t::now()), m_tick(ti), m_time(now)
    {
        for(Type t : values_of<Type>()){
            m_idsByType[t]  = {};
        }
    }


    Frame::~Frame()
    {
    }

    void    Frame::add(ThreadID th, const TachyonFrame& tac)
    {
        if(!(tac.object && tac.data && tac.snap))  
            return ;

        Types     types = tac.object->metaInfo().types();
        TachyonID id    = tac.object->id();

        //if(th){
            //m_owners[id]    = th;
        //}
        //m_types[id]     = types;
        m_allIds.insert(id);
        auto& tbit  = m_data[id];
        if(th)
            tbit.owner          = th;
        //tbit.types              = types;
        tbit.object             = tac.object;
        tbit.data               = tac.data;
        tbit.snap               = tac.snap;
        tbit.typedId            = *tac.object;
        for(Type t : values_of<Type>()){
            if(!types(t))
                continue;
            m_idsByType[t].insert(id);
        }
    }

    std::span<const TypedID>    Frame::children(TachyonID tac) const
    {
        const TachyonSnap*  sn  = snap(tac);
        if(!sn)
            return {};
        return sn->children;
    }

    bool Frame::contains(Type type, uint64_t id) const
    {
        if(!is_valid(type))
            return false;
        return m_idsByType[type].contains({id});
    }

    bool Frame::contains(TypedID tid) const
    {
        return m_data.contains(tid.id);
    }

    size_t Frame::count(Type t) const
    {
        if(!is_valid(t))
            return 0;
        return m_idsByType[t].size();
    }

    size_t Frame::count(children_k, TachyonID tid) const
    {
        const TachyonSnap*  sn  = snap(tid);
        if(!sn)
            return 0;
        
        size_t  ret = 0;
        for(TypedID t : sn->children){
            if(contains((TachyonID) t)){
                ++ ret;
            }
        }
        return ret;
    }

    size_t Frame::count(tachyon_k) const
    {
        return m_allIds.size();
    }
    
    const TachyonData*                  Frame::data_of(Type type, uint64_t id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end()){
            if(itr->second.typedId.types(type))
                return itr->second.data.ptr();
        }
        return nullptr;
    }
    
    const TachyonData*                  Frame::data_of(TachyonID tid) const
    {
        if(auto itr = m_data.find(tid); itr != m_data.end())
            return itr->second.data.ptr();
        return nullptr;
    }

    TachyonID                           Frame::first_of(Type type) const
    {
        if(!is_valid(type))
            return {};
        auto& tb = m_idsByType[type];
        if(tb.empty())
            return {};
        return *tb.begin();
    }


    TachyonID                           Frame::first_of(tachyon_k) const
    {
        if(m_allIds.empty())    [[unlikely]]
            return {};
        return *m_allIds.begin();
    }

    const std::set<TachyonID>&          Frame::ids_of(Type t) const
    {
        static const std::set<TachyonID> s_null;
        if(!is_valid(t))
            return s_null;
        return m_idsByType[t];
    }

    const TachyonMeta*                  Frame::meta_of(Type t, uint64_t id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end() && itr->second.object){
            if(itr->second.typedId.types(t))
                return &itr->second.object->metaInfo();
        }
        return nullptr;
    }

    const TachyonMeta*                  Frame::meta_of(TachyonID tid) const
    {
        if(auto itr = m_data.find(tid.id); itr != m_data.end()){
            if(itr->second.object)
                return &itr->second.object->metaInfo();
        }
        return nullptr;
    }
    
    Tachyon*    Frame::object_of(Type type, uint64_t id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end()){
            if(itr->second.typedId.types(type))
                return const_cast<Tachyon*>(itr->second.object.ptr());
        }
        return nullptr;
    }
    
    Tachyon*    Frame::object_of(TachyonID id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end())
            return const_cast<Tachyon*>(itr->second.object.ptr());
        return nullptr;
    }


    Tachyon*                            Frame::object(parent_k, TachyonID tac) const
    {
        return object(parent(tac));
    }
    
    Tachyon*                            Frame::object(root_k, TachyonID tac) const
    {
        return object(root(tac));
    }


    ThreadID                            Frame::owner(TachyonID tac) const
    {
        if(auto itr = m_data.find(tac); itr != m_data.end())
            return itr->second.owner;
        return {};
    }
    
    TypedID                             Frame::parent(TachyonID tac) const
    {
        const TachyonSnap*sn        = snap(tac);
        if(!sn)
            return {};
        return sn -> parent;
    }

    TypedID                             Frame::parent(Type t, TachyonID tac) const
    {
        for(const TachyonSnap* sn = snap(tac); sn && sn -> parent; sn = snap(sn->parent)){
            if(sn->parent(t))
                return sn->parent;
        }
        return {};
    }

    std::span<Proxy* const>             Frame::proxies(TachyonID tac) const
    {
        const TachyonSnap* ts = snap(tac);
        if(!ts)
            return {};
        return ts->proxies;
    }
    
    Proxy*                              Frame::proxy(TachyonID tac, const InterfaceMeta& ii) const
    {
        const TachyonSnap*  ts  = snap(tac);
        if(!ts)
            return nullptr;
        for(Proxy* p : ts->proxies){
            if(p->interface(INFO) == &ii)
                return p;
        }
        return nullptr;
    }

    void    Frame::report(Stream& out) const
    {
        out << "Report for Frame (" << m_number << ")\n"
            << "  Origin:        " << (uint64_t) m_origin << "\n"
            << "  Tick:          " << m_tick << "\n"
            << "  Clock:         " << std::format("{:%Y%m%d %H:%M:%S.%Z}", m_wallclock) << "\n"
            << "     - - - - - \n"
            << "  Cameras:       " << count(CAMERA) << "\n"
            << "  Camera³s:      " << count(CAMERA³) << "\n"
            << "  Controllers:   " << count(CONTROLLER) << "\n"
            << "  Cursors:       " << count(CURSOR) << "\n"
            << "  Desktops:      " << count(DESKTOP) << "\n"
            << "  Engines:       " << count(ENGINE) << "\n"
            << "  Gamepads:      " << count(GAMEPAD) << "\n"
            << "  GraphicsCards: " << count(GRAPHICS_CARD) << "\n"
            << "  Groups:        " << count(GROUP) << "\n"
            << "  Keyboards:     " << count(KEYBOARD) << "\n"
            << "  Kinetics:      " << count(KINETIC) << "\n"
            << "  Kinetic³s:     " << count(KINETIC³) << "\n"
            << "  Joysticks:     " << count(JOYSTICK) << "\n"
            << "  Layers:        " << count(LAYER) << "\n"
            << "  Lights:        " << count(LIGHT) << "\n"
            << "  Light³s:       " << count(LIGHT³) << "\n"
            << "  Managers:      " << count(MANAGER) << "\n"
            << "  Masters:       " << count(MASTER) << "\n"
            << "  Models:        " << count(MODEL) << "\n"
            << "  Mouses:        " << count(MOUSE) << "\n"
            << "  Physics:       " << count(PHYSICS) << "\n"
            << "  Rendereds:     " << count(RENDERED) << "\n"
            << "  Rendered³s:    " << count(RENDERED³) << "\n"
            << "  Scenes:        " << count(SCENE) << "\n"
            << "  Scene³s:       " << count(SCENE³) << "\n"
            << "  Spatials:      " << count(SPATIAL) << "\n"
            << "  Spatial²s:     " << count(SPATIAL²) << "\n"
            << "  Spatial³s:     " << count(SPATIAL³) << "\n"
            << "  Tachyons:      " << count(TACHYON) << "\n"
            << "  Threads:       " << count(THREAD) << "\n"
            << "  Viewers:       " << count(VIEWER) << "\n"
            << "  Widgets:       " << count(WIDGET) << "\n"
            << "  Windows:       " << count(WINDOW) << "\n"
        ;
    }

    TypedID                             Frame::root(Type type, TachyonID tac) const
    {
        TypedID     ret;
        TypedID     ttid    = typed(tac);
        if(ttid(type))
            ret = ttid;
        
        for(const TachyonSnap*  sn = snap(tac); sn && sn->parent; sn = snap(sn->parent)){
            if(sn->parent(type))
                ret = sn->parent;
        }
        
        return ret;
    }

    TypedID                             Frame::root(TachyonID tac) const
    {
        TypedID     ret = typed(tac);
        for(const TachyonSnap* sn = snap(tac); sn && sn->parent; sn = snap(sn->parent)){
            ret = sn->parent;
        }
        return ret;
    }

    const TachyonSnap*                 Frame::snap_of(Type type, uint64_t id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end()){
            if(itr->second.typedId.types(type))
                return itr->second.snap.ptr();
        }
        return nullptr;
    }
    
    const TachyonSnap*                 Frame::snap_of(TachyonID id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end())
            return itr->second.snap.ptr();
        return nullptr;
    }

    TypedID Frame::typed(TachyonID id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end())
            return itr->second.typedId;
        return {};
    }

    TypedID Frame::typed(StdThread st) const
    {
        return typed(Thread::standard(st));
    }
    
    Types   Frame::types(TachyonID id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end())
            return itr->second.typedId.types;
        return {};
    }

    ////////////////////////
    // FRAME BUILDER
    
    Frame::Builder::Builder(Frame& fp) : m_frame(fp)
    {
    }
    
    Frame::Builder::~Builder()
    {
    }
    
    void        Frame::Builder::add(ThreadID th, const ThreadData& tdata)
    {
        for(const TachyonFrame& tf : tdata.tachyons){
            if(!tf.object){
                //tachyonInfo << "frame build... item " << tf.object->ident() << " has no object";
                continue;
            }
            if(!tf.data){
                //tachyonInfo << "frame build... item " << tf.object->ident() << " has no data";
                continue;
            }
            if(!tf.snap){
                //tachyonInfo << "frame build... item " << tf.object->ident() << " has no snap";
                continue;
            }
                
            switch(tf.state){
            case TachyonThreadState::Normal:
                m_frame.add(th, tf);
                break;
            case TachyonThreadState::Pushed:
                //tachyonInfo << "frame build... item " << tf.object->ident() << " pushed";
                m_pushed.push_back({th, tf});
                break;
            case TachyonThreadState::Delete:
                //tachyonInfo << "frame build... item " << tf.object->ident() << " deleted";
                break;
            default:
                //tachyonInfo << "frame build... item " << tf.object->ident() << " unknown state";
                break;
            }
        }
    }
    
    void    Frame::Builder::finalize()
    {
        for(auto& p : m_pushed){
            if(m_frame.contains(p.second.object->id()))
                continue;
            m_frame.add(p.first, p.second);
        }
    }
    
}
