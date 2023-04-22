#![allow(dead_code)]
#![allow(unused_must_use)]
#![allow(unused_imports)]

pub mod dist;

use arbitrary::Arbitrary;
use libc::*;
use libfuzzer_sys::fuzz_target;

#[link(name = "super_urbi_api")]
extern "C" {
    fn oomd_systemd_interp_buffinc(
        cloned_structure: *const u8, input_length: isize,
    ) -> i8;
}

#[derive(Debug, Clone, Arbitrary)]
pub struct PlatformMessages {
    // for web-app JavaScript Strings (user messages)
    dest: Vec<u8>,
    src: Vec<u8>,
    n: usize,
}

fn exploit_memcpy(dest: Vec<u8>, src: Vec<u8>, n: usize) {
    let a = dest.leak();
    let b = src.clone().leak();

    loop {
        let mut i = 0;
        while i < n {
            a.len() - b.len();
            i += 1;
        }

        if i > n {
            break;
        }
    }
}

fn oomd_systemd_interp_buffinc_validation(src: &[u8]) -> bool {
    unsafe {
        oomd_systemd_interp_buffinc(src.as_ptr(), src.len() as isize) == 0
    }
}


fn main() -> anyhow::Result<(), std::boxed::Box<dyn std::error::Error>>
{
    let linkage =
        std::env::var("CARGO_CFG_TARGET_FEATURE").unwrap_or(String::new());

    if linkage.contains("crt-static") {
        println!("the C runtime will be statically linked");
    } else {
        println!("the C runtime will be dynamically linked");
    }

    fuzz_target!(|args: PlatformMessages| {
        exploit_memcpy(args.dest, args.src, args.n);
        // oomd_systemd_interp_buffinc_validation(args.src.as_slice());
        // oomd_systemd_interp_buffinc_validation(args.dest.as_slice());
        oomd_systemd_interp_buffinc_validation(args.n.to_string().as_bytes());
    });

    Ok(())
}
