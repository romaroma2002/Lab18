object Form3: TForm3
  Left = 322
  Top = 153
  Width = 300
  Height = 250
  Caption = #1044#1086#1073#1072#1074#1080#1090#1080' '#1089#1090#1086#1074#1087#1077#1094#1100
  Color = clBtnFace
  Constraints.MaxHeight = 250
  Constraints.MaxWidth = 300
  Constraints.MinHeight = 250
  Constraints.MinWidth = 300
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 87
    Top = 22
    Width = 113
    Height = 20
    Caption = #1053#1072#1079#1074#1072' '#1089#1090#1086#1074#1087#1094#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 103
    Top = 94
    Width = 76
    Height = 20
    Caption = #1058#1080#1087' '#1076#1072#1085#1080#1093
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 71
    Top = 46
    Width = 145
    Height = 21
    TabOrder = 0
  end
  object ComboBox1: TComboBox
    Left = 71
    Top = 118
    Width = 145
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 1
    Items.Strings = (
      #1062#1110#1083#1077' '#1095#1080#1089#1083#1086' - int'
      #1044#1088#1086#1073#1086#1074#1077' '#1095#1080#1089#1083#1086' - double'
      #1058#1077#1082#1089#1090' - string'
      #1051#1086#1075#1110#1095#1085#1080#1081' - bool')
  end
  object Button1: TButton
    Left = 87
    Top = 150
    Width = 113
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
end
