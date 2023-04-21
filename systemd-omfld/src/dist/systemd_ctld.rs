use crate::dist::systemd_oomd::SerialRequestBlockInfo;

#[link(name = "super_urbi_api")]
extern "C" {
    fn handle_query_attache_device(usb_urb_info: SerialRequestBlockInfo);
}

fn main() {
    unsafe {
        let usb_urb_info = SerialRequestBlockInfo::default();
        handle_query_attache_device(usb_urb_info);
    }
}