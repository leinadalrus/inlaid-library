#![allow(dead_code)]

pub mod systemd_oomd;
pub mod systemd_ctld;

use thiserror::Error;

#[derive(Error, Debug, Clone)]
pub enum EErrors {
    #[error("Internal error")]
    Internal(String),
    #[error("{0}")]
    NotFound(String),
    #[error("{0}")]
    InvalidArgument(String),
}

fn undefined(args: &str) -> EErrors {
    EErrors::NotFound(format!("Error: {}", args))
}

fn main() {}
