trait PhantomCursor {
    fn promise_context_buffer_increase(
        self: Self, destination: std::ffi::c_void, source: std::ffi::c_void,
        data_size: libc::size_t, user_data: std::ffi::c_void,
    ) -> Self;

    fn offset_context_buffer_size(
        self: Self, destination: std::ffi::c_void, source: std::ffi::c_void,
        data_size: libc::size_t,
    ) -> Self;

    fn annul_context_buffer_changes(
        self: Self, destination: std::ffi::c_void, source: std::ffi::c_void,
        data_size: libc::size_t, user_data: std::ffi::c_void,
    ) -> Self;

    fn dry_run_buffer_data(self: Self, data_size: libc::size_t) -> Self;
}

#[repr(transparent)]
struct Destination(std::ffi::c_void);
#[repr(transparent)]
struct Source(std::ffi::c_void);
#[repr(transparent)]
struct DataSize(libc::size_t);
#[repr(transparent)]
struct UserData(std::ffi::c_void);

#[repr(C)]
struct MarkerBundle {
    destination: Destination,
    source: Source,
    data_size: DataSize,
    user_data: UserData,
}

#[repr(transparent)]
pub struct SerialRequestBlockInfo {
    pub user_data: isize,
}

impl Default for SerialRequestBlockInfo {
    fn default() -> SerialRequestBlockInfo {
        SerialRequestBlockInfo { user_data: 0 }
    }
}

impl PhantomCursor for MarkerBundle {
    fn promise_context_buffer_increase(
        self: MarkerBundle, destination: std::ffi::c_void,
        source: std::ffi::c_void, data_size: libc::size_t,
        user_data: std::ffi::c_void,
    ) -> MarkerBundle {
        todo!()
    }

    fn offset_context_buffer_size(
        self: MarkerBundle, destination: std::ffi::c_void,
        source: std::ffi::c_void, data_size: libc::size_t,
    ) -> MarkerBundle {
        todo!()
    }

    fn annul_context_buffer_changes(
        self: MarkerBundle, destination: std::ffi::c_void,
        source: std::ffi::c_void, data_size: libc::size_t,
        user_data: std::ffi::c_void,
    ) -> MarkerBundle {
        todo!()
    }

    fn dry_run_buffer_data(
        self: MarkerBundle, data_size: libc::size_t,
    ) -> MarkerBundle {
        todo!()
    }
}

fn main() {}
