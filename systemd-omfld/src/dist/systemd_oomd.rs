#[repr(transparent)]
pub struct SerialRequestBlockInfo {
    pub user_data: isize,
}

impl Default for SerialRequestBlockInfo {
    fn default() -> SerialRequestBlockInfo {
        SerialRequestBlockInfo { user_data: 0 }
    }
}

fn main() {}
