#
# Be sure to run `pod lib lint NAME.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "mulle-tidy"
  s.version          = 18.48.9
  s.summary          = "HTML tidy fork from Mulle kybernetiK"
  s.description      = <<-DESC
                       Meaningful description, that this is a
                       HTML tidy fork from Mulle kybernetiK
                       DESC
  s.homepage         = "http://www.mulle-kybernetik.com/weblog"
  s.license          = 'MIT'
  s.author           = { "Nat!" => "nat@mulle-kybernetik.com" }
  s.source           = { :git => "http://www.mulle-kybernetik.com/repositories/mulle-tidy", :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/EXAMPLE'

  s.platform              = :ios, '5.0'
  s.ios.deployment_target = '5.0'
  s.osx.deployment_target = '10.4'
  s.requires_arc = false

  s.source_files = 'include', 'src/*.{c,h}'
  s.resources    = 'src/*.doxy'

  # s.ios.exclude_files = 'src/osx'
  # s.osx.exclude_files = 'src/ios'
  s.public_header_files = 'include/buffio.h', 'include/platform.h', 'include/tidy.h', 'include/tidyenum.h'
  # s.frameworks = 'SomeFramework', 'AnotherFramework'
  # s.dependency 'JSONKit', '~> 1.4'
end
